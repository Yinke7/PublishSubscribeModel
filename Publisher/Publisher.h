#ifndef __PUBLISH_H__
#define __PUBLISH_H__

/**
 * @brief 订阅事件链表
 */
typedef struct PublisherNode
{
    char *event;                // 事件
    void *data;                 // 数据
    struct PublisherNode *prev; // 前一个发布信息
    struct PublisherNode *next; // 后一个发布信息
} PubNode_s;

/**
 * @brief 发布事件及其数据到数据中心
 * @param event: 发布的事件
 * @param data: 对应的数据
 */
void SendPublishEvent(char *event, void *data);

/**
 * @brief 从数据中心清除发布的事件及其数据
 * @param event: 清除发布的事件
 * @param data: 对应的数据
 */
void ClearPublishEvent(char *event, void *data);

extern PubNode_s PubHead;

#endif