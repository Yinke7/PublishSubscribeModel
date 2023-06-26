#include "stdio.h"
#include "DataCenter.h"
#include "Subscriber.h"
#include "Publisher.h"

void ProcDataCenter(void)
{
    SubNode_s *sub_pos = &SubHead;
    PubNode_s *pub_pos = &PubHead;

    // 查找发布事件
    while (pub_pos != NULL)
    {
        if (pub_pos->event != NULL)
        {
            break;
        }
        pub_pos = pub_pos->next;
    }

    // 未找到有效的发布事件
    if (pub_pos)
    {

        // 执行发布事件对应的回调函数
        while (sub_pos != NULL)
        {
            if (pub_pos->event != NULL && pub_pos->event == sub_pos->event)
            {
                sub_pos->func(pub_pos->data);
                ClearPublishEvent(pub_pos->event, pub_pos->data);
            }
            sub_pos = sub_pos->next;
        }
    }
}
