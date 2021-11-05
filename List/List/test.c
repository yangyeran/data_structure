#include "List.h"
void test1()
{
	ListNode*pHead=ListCreate();
	ListPushFront(pHead,1);
	ListPushFront(pHead,2);
	ListPushFront(pHead,3);
	ListPrint(pHead);
	printf("\n");
	ListPopBack(pHead);
	ListPrint(pHead);
	ListDestory(pHead);
}
void test2()
{
	ListNode* pHead = ListCreate();
	ListPushBack(pHead,1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPrint(pHead);
	printf("\n");
	ListPopFront(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	ListDestory(pHead);
}
void test3()
{
	ListNode* pHead = ListCreate();
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPrint(pHead);
	printf("\n");
	ListPopBack(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListDestory(pHead);
}
void test4()
{
	ListNode* pHead = ListCreate();
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPrint(pHead);
	printf("\n");
	ListInsert(pHead->next->next,5);
	ListInsert(pHead->prev,6);
	ListPrint(pHead);
	ListDestory(pHead);
}
int main()
{
	test1();
	//test2();
	//test3();
	//test4();
}