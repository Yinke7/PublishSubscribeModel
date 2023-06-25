#ifndef __PUBLISH_H__
#define __PUBLISH_H__



/**
 * @brief 
 * 订阅事件链表
 */
typedef struct PublisherNode
{
    char *event;
    void *data;
    PublisherNode *next;
}PubNode_s;


/**
 * @brief
 * 发送发布事件
 * 添加发布事件及其数据到数据中心
 * 数据中心执行后自动删除事件
 */
void SendPublishEvent(char *event, void *data);


extern PubNode_s *PubHead;

#endif 