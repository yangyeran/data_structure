#include "List.h"
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}

//创建新的节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	NewNode->next = NULL;
	NewNode->prev = NULL;
	NewNode->data = x;
	return NewNode;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* front = pos->prev;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	front->next = newNode;
	newNode->prev = front;
	newNode->next = pos;
	pos->prev = newNode;
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);
	/*ListNode* newNode=BuyListNode(x);
	ListNode* cur = pHead->next;
	pHead->next = newNode;
	newNode->next = cur;
	newNode->prev = pHead;
	cur->prev = newNode;*/
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
	//ListNode* newNode = BuyListNode(x);
	//ListNode* cur = pHead->prev;//找到最后一个节点
	////建立链接关系，从后向前找
	//cur->next = newNode;
	//newNode->prev = cur;
	//newNode->next = pHead;
	//pHead->prev = newNode;
}


// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead->next != pHead);
	//不能用下面这个代码，因为如果只有一个节点，头尾指针指向的是相等的
	//assert(pHead->next==pHead->prev);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* front = pos->prev;
	ListNode* next = pos->next;
	front->next = next;
	next->prev = front;
	free(pos);
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListErase(pHead->next);
	//assert(pHead->next!=pHead);//不能为空链表
	//ListNode* cur = pHead->next;
	//ListNode* next = pHead->next->next;
	//pHead->next = next;
	//next->prev = pHead;
	//free(cur);
}

//尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListErase(pHead->prev);
	//ListNode* tail = phead->prev;//最后一个节点
	//tail->prev->next = phead;
	//phead->prev = tail->prev;
	//free(tail);
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)//这种判断会少free一个节点所以后面要补上
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
}


// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	assert(pHead != pHead->next);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}