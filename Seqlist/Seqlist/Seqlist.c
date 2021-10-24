# define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"
int SeqListFind(SeqList* ps, SLDateType x)// ˳������
{
	int count = 0;
	int copy = ps->size;
	assert(ps != NULL&&(ps->size!=0));
	while (copy--)
	{
		if (ps->a[copy] == x)
		{
			return copy;
		}
	}
	return -1;
}

void SeqListInit(SeqList* ps)//��ʼ������
{
	ps->size = 0;
	ps->a = NULL;
	ps->capacity =0;
}

void SeqListDestory(SeqList* ps)//����
{
	ps->size = 0;
	ps->capacity = 0;
	free(ps->a);
	ps->a = NULL;
}


void SeqListPrint(SeqList* ps)//��ӡ����
{
	assert(ps->size != 0);
		for (int i = 0; i <(ps->size); i++)
		{

			printf("%d ", ps->a[i]);
		}
}

void SeqListPushBack(SeqList* ps, SLDateType x)//β��
{
	SeqListInsert(ps,ps->size,x);
}

void SeqListPushFront(SeqList* ps , SLDateType x)//ͷ��
{
	SeqListInsert(ps, 0, x);
}
//���ݺ���
SeqList* Dilatation(SeqList* ps)
{
	int* src = NULL;
	if (ps->size == ps->capacity)
	{
		src = (int*)realloc(ps->a ,(2+ps->capacity*ps->capacity)*sizeof(int));
		if (src == NULL)
			exit(-1);
		ps->a = src;
		ps->capacity=2 + ps->capacity*ps->capacity;
	}
	return ps;
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	int i = 0;
	//��������ռ��㹻�Ϳռ䲻��
	if (ps->capacity==ps->size)//���ڵ����
	{
		ps = Dilatation(ps);
	}
	if (pos >= 0 && pos <= (ps->size + 1))//˳���û�и�����ÿ��Ԫ�������δ洢��
	{//�㹻�Ļ����ǲ�����
		for (i = 0; i < (ps->size - pos); i++)
		{
			ps->a[ps->size - i] = ps->a[ps->size - i-1];
		}
		ps->a[pos] = x;
		ps->size++;
	}
}


void SeqListPopFront(SeqList* ps)//ͷɾ
{
	SeqListErase(ps, 1);
}

void SeqListPopBack(SeqList* ps)//βɾ
{
	ps->size--;
}

void SeqListErase(SeqList* ps, size_t pos)//����λ��ɾ��
{
	int i = 0;
	assert(ps->size != 0);
	for (i = pos-1; i <=(ps->size - pos); i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}