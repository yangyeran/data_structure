#include<stdio.h>
#include<stdlib.h>
  struct ListNode 
  {
     int val;
     struct ListNode *next;
  };
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    //�ø��ڱ�λ����Ϊ������ı�ͷ
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
        //�жϴ�С
        if ((l1->val) < (l2->val))
        {
            if (NewHead->next == NULL)//����������û��Ԫ�أ���ͷβָ��ָ���һ��Ԫ��
            {
                NewHead->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            //�������β��Ԫ����
            else
            {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
        }
        else//������l2�����ֵ����l1�����ֵ
        {
            if (NewHead->next == NULL)//����������û��Ԫ�أ���ͷβָ��ָ���һ��Ԫ��
            {
                NewHead->next = l2;
                tail = l2;
                l2 = l2->next;
            }
            //�������β��Ԫ����
            else
            {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
    }
    //�߳�������������һ����NULL��
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