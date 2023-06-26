#include "stdio.h"
#include "stdbool.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#include "Subscriber.h"

SubNode_s SubHead = {
    .event = NULL,
    .func = NULL,
    .prev = NULL,
    .next = NULL,
};

static SemaphoreHandle_t Sub_Mutex;

void AddSubscriberEvent(char *event, HandleEvent func)
{

    SubNode_s *node = (SubNode_s *)malloc(sizeof(SubNode_s));

    // 申请内存失败
    if (!node)
    {
        return;
    }

    // 上锁
    if (!Sub_Mutex)
    {
        Sub_Mutex = xSemaphoreCreateMutex();
    }
    if (xSemaphoreTake(Sub_Mutex, portMAX_DELAY / portTICK_PERIOD_MS) == pdFALSE)
    {
        return;
    }

    // 将指定订阅追加到链表尾部
    node->event = event;
    node->func = func;
    node->prev = NULL;
    node->next = NULL;
    SubNode_s *pos = &SubHead;
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    pos->next = node;
    node->prev = pos;

    // 释放锁
    xSemaphoreGive(Sub_Mutex);
}

void DeleteSubscriberEvent(char *event, HandleEvent func)
{
    // 锁被占用
    if (!Sub_Mutex)
    {
        Sub_Mutex = xSemaphoreCreateMutex();
    }
    if (xSemaphoreTake(Sub_Mutex, portMAX_DELAY / portTICK_PERIOD_MS) == pdFALSE)
    {
        return;
    }

    // 从链表中删除
    SubNode_s *pos = &SubHead;
    while (pos != NULL)
    {
        if (pos->event == event && pos->func == func)
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
    xSemaphoreGive(Sub_Mutex);
}
