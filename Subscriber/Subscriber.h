#ifndef __SUBSCRIBE_H__
#define __SUBSCRIBE_H__

/**
 * @brief 订阅处理函数
 */
typedef void (*HandleEvent)(void *);

/**
 * @brief 订阅事件链表
 */
typedef struct SubscriberNode
{
    char *event;                 // 事件
    HandleEvent func;            // 回调函数
    struct SubscriberNode *prev; // 前一个订阅
    struct SubscriberNode *next; // 后一个订阅
} SubNode_s;

/**
 * @brief 添加订阅事件及其回调函数到数据中心
 * @param event: 订阅的事件
 * @param func: 对应的回调函数
 */
void AddSubscriberEvent(char *event, HandleEvent func);

/**
 * @brief 从数据中心删除订阅事件
 * @param event: 取消订阅的事件
 * @param func: 对应的回调函数
 */
void DeleteSubscriberEvent(char *event, HandleEvent func);

extern SubNode_s SubHead;

#endif