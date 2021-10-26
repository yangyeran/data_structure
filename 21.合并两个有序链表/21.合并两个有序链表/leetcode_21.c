#include<stdio.h>
#include<stdlib.h>
  struct ListNode 
  {
     int val;
     struct ListNode *next;
  };
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    //用个哨兵位来作为新链表的表头
    if (l1 == NULL && l2 == NULL)
        return NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode* NewHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = NULL;
    NewHead->next = NULL;
    while (l1 && l2)
    {
        //判断大小
        if ((l1->val) < (l2->val))
        {
            if (NewHead->next == NULL)//新链表里面没有元素，将头尾指针指向第一个元素
            {
                NewHead->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            //这里就是尾插元素了
            else
            {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
        }
        else//这里是l2里面的值大于l1里面的值
        {
            if (NewHead->next == NULL)//新链表里面没有元素，将头尾指针指向第一个元素
            {
                NewHead->next = l2;
                tail = l2;
                l2 = l2->next;
            }
            //这里就是尾插元素了
            else
            {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
    }
    //走出来就是其中有一个到NULL了
    if (l2 != NULL)
    {
        while (l2)
        {
            tail->next = l2;
            tail = tail->next;
            l2 = l2->next;
        }
    }
    if (l1 != NULL)
    {
        while (l1)
        {
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        }
    }
    return NewHead->next;
}