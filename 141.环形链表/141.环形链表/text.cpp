#include<stdio.h>
#include<stdlib.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
bool hasCycle(struct ListNode* head) {
    if (head == NULL)
        return false;
    struct ListNode* cur = head;
    struct ListNode* next = head;
    while (next && next->next)
    {
        cur = cur->next;
        next = next->next->next;
        if (cur == next)
            return true;
    }
    return false;
}