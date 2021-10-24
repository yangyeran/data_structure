# define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"
int SeqListFind(SeqList* ps, SLDateType x)// 顺序表查找
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

void SeqListInit(SeqList* ps)//初始化函数
{
	ps->size = 0;
	ps->a = NULL;
	ps->capacity =0;
}

void SeqListDestory(SeqList* ps)//销毁
{
	ps->size = 0;
	ps->capacity = 0;
	free(ps->a);
	ps->a = NULL;
}


void SeqListPrint(SeqList* ps)//打印函数
{
	assert(ps->size != 0);
		for (int i = 0; i <(ps->size); i++)
		{

			printf("%d ", ps->a[i]);
		}
}

void SeqListPushBack(SeqList* ps, SLDateType x)//尾插
{
	SeqListInsert(ps,ps->size,x);
}

void SeqListPushFront(SeqList* ps , SLDateType x)//头插
{
	SeqListInsert(ps, 0, x);
}
//扩容函数
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

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	int i = 0;
	//分情况，空间足够和空间不足
	if (ps->capacity==ps->size)//大于的情况
	{
		ps = Dilatation(ps);
	}
	if (pos >= 0 && pos <= (ps->size + 1))//顺序表没有负数且每个元素是依次存储的
	{//足够的话就是插入了
		for (i = 0; i < (ps->size - pos); i++)
		{
			ps->a[ps->size - i] = ps->a[ps->size - i-1];
		}
		ps->a[pos] = x;
		ps->size++;
	}
}


void SeqListPopFront(SeqList* ps)//头删
{
	SeqListErase(ps, 1);
}

void SeqListPopBack(SeqList* ps)//尾删
{
	ps->size--;
}

void SeqListErase(SeqList* ps, size_t pos)//任意位置删除
{
	int i = 0;
	assert(ps->size != 0);
	for (i = pos-1; i <=(ps->size - pos); i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}