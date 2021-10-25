# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL)
	{
		return NULL;
	}
	if (head->next == NULL)
		return head;
	struct ListNode*n1 = head;
	struct ListNode*n2 = head->next;
	struct ListNode*n3 = n2->next;
	n1->next = NULL;
	while (n2->next)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3!= NULL)
			n3 = n3->next;
	}
	n2->next = n1;
	return n2;
}
int main()
{
	struct ListNode* s1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	s1->val = 2;
	s2->val = 3;
	s3->val = 4;
	s4->val = 5;
	s5->val = 6;
	s6->val = 7;
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = s5;
	s5->next = s6;
	s6->next = NULL;
	struct ListNode*head = reverseList(s1);
	for (int i = 0; i < 1; i++)
	{
		printf("%d ", head->val);
		head = head->next;
	}
}