#include "List.h"
// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}

//�����µĽڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	NewNode->next = NULL;
	NewNode->prev = NULL;
	NewNode->data = x;
	return NewNode;
}
// ˫��������pos��ǰ����в���
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
// ˫������ͷ��
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

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
	//ListNode* newNode = BuyListNode(x);
	//ListNode* cur = pHead->prev;//�ҵ����һ���ڵ�
	////�������ӹ�ϵ���Ӻ���ǰ��
	//cur->next = newNode;
	//newNode->prev = cur;
	//newNode->next = pHead;
	//pHead->prev = newNode;
}


// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead->next != pHead);
	//����������������룬��Ϊ���ֻ��һ���ڵ㣬ͷβָ��ָ�������ȵ�
	//assert(pHead->next==pHead->prev);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* front = pos->prev;
	ListNode* next = pos->next;
	front->next = next;
	next->prev = front;
	free(pos);
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListErase(pHead->next);
	//assert(pHead->next!=pHead);//����Ϊ������
	//ListNode* cur = pHead->next;
	//ListNode* next = pHead->next->next;
	//pHead->next = next;
	//next->prev = pHead;
	//free(cur);
}

//βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListErase(pHead->prev);
	//ListNode* tail = phead->prev;//���һ���ڵ�
	//tail->prev->next = phead;
	//phead->prev = tail->prev;
	//free(tail);
}

// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)//�����жϻ���freeһ���ڵ����Ժ���Ҫ����
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
}


// ˫���������
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