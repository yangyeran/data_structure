#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;
//˫������βɾ
void ListPopBack(ListNode* phead);


// �������������ͷ���.
ListNode* ListCreate();


//�����µĽڵ�
ListNode* BuyListNode(LTDataType x);


// ˫����������
void ListDestory(ListNode* pHead);


// ˫�������ӡ
void ListPrint(ListNode* pHead);


// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);


// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);


// ˫������ͷɾ
void ListPopFront(ListNode* pHead);


// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x);


// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);


// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
