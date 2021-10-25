# define _CRT_SECURE_NO_WARNINGS 1
#include"slist.h"
test1()//²âÊÔ¿ª±ÙÓë´òÓ¡
{
	SListNode* s1=BuySListNode(1);
	SListNode* s2=BuySListNode(2);
	SListNode* s3=BuySListNode(3);
	SListNode* s4=BuySListNode(4);
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = NULL;
	SListPrint(s1);
	SListDestory(s1);
}



void  test2()//²âÊÔÎ²²å
{
	SListNode* head=BuySListNode(1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPrint(head);
	SListDestory(head);
}
void test3()//²âÊÔÍ·²å
{
	SListNode* head = BuySListNode(1);
	SListPushFront(&head, 2);
	SListPushFront(&head, 3);
	SListPushFront(&head, 4);
	SListPrint(head);
	SListNode* ret=SListFind(head, 4);
	SListDestory(head);
}

void test4()//²âÊÔÎ²É¾
{
	SListNode* head = BuySListNode(1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPrint(head);
	printf("\n");
	SListPopBack(&head);
	SListPopBack(&head);
	SListPrint(head);
	SListDestory(head);
}

void  test5()
{
	SListNode* head = BuySListNode(1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPrint(head);
	printf("\n");
	SListPopFront(&head);
	SListPopFront(&head);
	SListPrint(head);
	SListDestory(head);
}
void  test6()
{
	SListNode* head = BuySListNode(1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPrint(head);
	printf("\n");
	SListInsertAfter(head->next,5);
	SListPrint(head);
	SListDestory(head);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
}



