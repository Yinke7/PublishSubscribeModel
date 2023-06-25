#ifndef __SUBSCRIBE_H__
#define __SUBSCRIBE_H__

/**
 * @brief 
 * 订阅处理函数
 */
typedef void (*HandleEvent)(void*);

/**
 * @brief 
 * 订阅事件链表
 */
typedef struct SubscriberNode
{
    char *event;
    HandleEvent func;
    PublisherNode *next;
}SubNode_s;

/**
 * @brief
 * 订阅事件
 * 添加订阅事件及其回调函数到数据中心
 */
void AddSubscriberEvent(char *event, HandleEvent func);

/**
 * @brief
 * 取消订阅事件
 * 从数据中心删除订阅事件
 */
void DeleteSubscriberEvent(char *event, HandleEvent func);


extern SubNode_s *SubHead;

#endif 