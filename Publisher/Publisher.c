#include "stdio.h"
#include "stdbool.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#include "Publisher.h"

PubNode_s PubHead = {
    .event = NULL,
    .data = NULL,
    .prev = NULL,
    .next = NULL,
};

static SemaphoreHandle_t Pub_Mutex;

void SendPublishEvent(char *event, void *data)
{
    // 锁被占用
    if (!Pub_Mutex)
    {
        Pub_Mutex = xSemaphoreCreateMutex();
    }
    if (xSemaphoreTake(Pub_Mutex, portMAX_DELAY / portTICK_PERIOD_MS) == pdFALSE)
    {
        return;
    }

    PubNode_s *node = (PubNode_s *)malloc(sizeof(PubNode_s));

    // 申请内存失败
    if (!node)
    {
        return;
    }

    // 将发布信息追加到链表尾部
    node->event = event;
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    PubNode_s *pos = &PubHead;
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    pos->next = node;
    node->prev = pos;

    // 释放锁
    xSemaphoreGive(Pub_Mutex);
}

void ClearPublishEvent(char *event, void *data)
{
    // 锁被占用
    if (!Pub_Mutex)
    {
        Pub_Mutex = xSemaphoreCreateMutex();
    }
    if (xSemaphoreTake(Pub_Mutex, portMAX_DELAY / portTICK_PERIOD_MS) == pdFALSE)
    {
        return;
    }

    // 从链表中删除
    PubNode_s *pos = &PubHead;
    while (pos != NULL)
    {
        if (pos->event == event && pos->data == data)
        {
            pos->prev->next = pos->next;
            if (pos->next)
            {
                pos->next->prev = pos->prev;
            }
            free(pos);
            break;
        }
        pos = pos->next;
    }

    // 释放锁
    xSemaphoreGive(Pub_Mutex);
}