#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if (pHead == NULL)//判断不为空表
            return NULL;
        ListNode* small = (ListNode*)malloc(sizeof(ListNode));//定义出两个头节点
        ListNode* big = (ListNode*)malloc(sizeof(ListNode));
        ListNode* small_tail = small;//定义两个尾节点，共同存储开辟的地址，这样只需要改变tail
        ListNode* big_tail = big;
        ListNode* cur = pHead;//遍历用的节点
        while (cur)
        {
            if ((cur->val) < x)//小于接到small后面
            {
                small_tail->next = cur;
                small_tail = cur;
            }
            else
            {
                big_tail->next = cur;
                big_tail = cur;
            }
            cur = cur->next;
        }
        big_tail->next = NULL;
        small_tail->next = big->next;
        pHead = small->next;
        free(small);
        free(big);
        return pHead;
    }
};