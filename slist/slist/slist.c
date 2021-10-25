# define _CRT_SECURE_NO_WARNINGS 1
#include"slist.h"


// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

// �������ӡ
void SListPrint(SListNode* plist)
{
	while (plist)
	{
		printf("%d ", plist->data);
		plist = plist->next;
	}
}

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* pront = *pplist;
	//�ж�pplist�ǲ���Ϊ��
	if(*pplist!=NULL)
	{
		SListNode* Newnode = BuySListNode(x);//����һ���ڵ�
		while (pront->next != NULL)
		{
			pront = pront->next;
		}
		pront->next = Newnode;//����
	}
	else//��
	{
		*pplist=BuySListNode(x);
	}
}

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pplist;
	*pplist = newNode;
}

//������Ĳ���
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
	return NULL;//�Ҳ���
}

// �������βɾ
void SListPopBack(SListNode** pplist)
{
	//�����ǲ��ǿձ�
	assert(*pplist!=NULL);
	SListNode* tail = *pplist;
	if ((*pplist)->next == NULL)//ֻ��һ���ڵ�
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

// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	//��һ��ָ�����������ĵ�ַ
	SListNode* cur =(*pplist)->next;
	assert(*pplist!=NULL);//���ǲ���Ϊ�ձ�
	free(*pplist);
	*pplist = cur;
}


// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿��������������ֻ���Ǵ�ǰ����ң��Ҳ���posǰ���λ��
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
	else//���൱����β��
	{
		pos->next = cur;
	}
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã���������ǰ��Ľڵ���סpos�ĵ�ַ���ᵼ���Ѿ��ͷŵĿռ䱻����
void SListEraseAfter(SListNode* pos)
{
	assert(pos->next!=NULL);
	SListNode* cur = pos->next;
	SListNode* next = cur->next;
	pos->next = next;
	free(cur);
}
// �����������
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