#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

 struct ListNode 
 {
     int val;
     struct ListNode *next;
  };
 

 //¿ìÂýÖ¸Õë
struct ListNode* middleNode(struct ListNode* head) {
    if (head->next == NULL)
        return head;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while ((fast != NULL) && (fast->next != NULL))
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    //fast==null
    return slow;
}
int main()
{
	struct ListNode* s1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	s1->val = 2;
	s2->val = 3;
	s3->val = 4;
	s4->val = 5;
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = NULL;
	struct ListNode* head = middleNode(s1);
	printf("%d ", head->val);
	return 0;
}