#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
// 带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;
//双向链表尾删
void ListPopBack(ListNode* phead);


// 创建返回链表的头结点.
ListNode* ListCreate();


//创建新的节点
ListNode* BuyListNode(LTDataType x);


// 双向链表销毁
void ListDestory(ListNode* pHead);


// 双向链表打印
void ListPrint(ListNode* pHead);


// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);


// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);


// 双向链表头删
void ListPopFront(ListNode* pHead);


// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);


// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);


// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);
