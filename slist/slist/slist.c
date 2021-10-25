# define _CRT_SECURE_NO_WARNINGS 1
#include"slist.h"


// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	while (plist)
	{
		printf("%d ", plist->data);
		plist = plist->next;
	}
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* pront = *pplist;
	//判断pplist是不是为空
	if(*pplist!=NULL)
	{
		SListNode* Newnode = BuySListNode(x);//创建一个节点
		while (pront->next != NULL)
		{
			pront = pront->next;
		}
		pront->next = Newnode;//插入
	}
	else//空
	{
		*pplist=BuySListNode(x);
	}
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pplist;
	*pplist = newNode;
}

//单链表的查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;//找不到
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	//考虑是不是空表
	assert(*pplist!=NULL);
	SListNode* tail = *pplist;
	if ((*pplist)->next == NULL)//只有一个节点
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	//拿一个指针来储存后面的地址
	SListNode* cur =(*pplist)->next;
	assert(*pplist!=NULL);//还是不能为空表
	free(*pplist);
	*pplist = cur;
}


// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？————单链表只能是从前向后找，找不到pos前面的位置
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	SListNode* next = pos->next;
	cur->next = NULL;
	cur->data = x;
	if (pos->next != NULL)
	{
		pos->next = cur;
		cur->next = next;
	}
	else//就相当于是尾插
	{
		pos->next = cur;
	}
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？————前面的节点会记住pos的地址，会导致已经释放的空间被访问
void SListEraseAfter(SListNode* pos)
{
	assert(pos->next!=NULL);
	SListNode* cur = pos->next;
	SListNode* next = cur->next;
	pos->next = next;
	free(cur);
}
// 单链表的销毁
void SListDestory(SListNode* plist)
{
	SListNode*cur = plist;
	while (plist != NULL)
	{
		plist = plist->next;
		free(cur);
		cur = plist;
	}
	plist = NULL;
}