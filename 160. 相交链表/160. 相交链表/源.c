#include<stdio.h>
#include<stdlib.h>
  struct ListNode {
      int val;
     struct ListNode *next;
  };
 
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;
    struct ListNode* cur1 = headA;
    struct ListNode* cur2 = headB;
    int count1, count2;
    count1 = count2 = 0;//计数
    while (cur1->next)//走到最后一个节点，不走到尾
    {
        cur1 = cur1->next;
        count1++;
    }
    while (cur2->next)
    {
        cur2 = cur2->next;
        count2++;
    }
    if (cur1 != cur2)
        return NULL;
    if (count1 < count2)//就是固定让上边的那条链最长
    {
        struct ListNode* temp = headA;
        headA = headB;
        headB = temp;
    }
    int k = abs(count1 - count2);
    cur1 = headA;
    cur2 = headB;
    while (k--)//让长的先走
    {
        cur1 = cur1->next;
    }
    while (cur1)
    {
        if (cur1 == cur2)
            return cur1;
        else
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    return NULL;
}