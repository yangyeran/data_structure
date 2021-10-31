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
        if (pHead == NULL)//�жϲ�Ϊ�ձ�
            return NULL;
        ListNode* small = (ListNode*)malloc(sizeof(ListNode));//���������ͷ�ڵ�
        ListNode* big = (ListNode*)malloc(sizeof(ListNode));
        ListNode* small_tail = small;//��������β�ڵ㣬��ͬ�洢���ٵĵ�ַ������ֻ��Ҫ�ı�tail
        ListNode* big_tail = big;
        ListNode* cur = pHead;//�����õĽڵ�
        while (cur)
        {
            if ((cur->val) < x)//С�ڽӵ�small����
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