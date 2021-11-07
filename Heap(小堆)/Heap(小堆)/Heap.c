#include "Heap.h"
//初始化函数
void HeapInit(HP* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}
//交换函数
void Swap(HPDataType* hp, HPDataType* hy)
{
	HPDataType temp = *hp;
	*hp = *hy;
	*hy = temp;
}
void AdjustUp(HPDataType* a, int child)
{
	//如果插入的数据小于父亲节点那么交换两个的位置
	//大堆
	assert(a);
	int parent = (child - 1) / 2;
	//child如果等于0则表示没有父亲节点了所以直接跳出
	while (child > 0)
	{
		//如果孩子大于父亲就交换两个人的值，并且下标也需要改变
		if (a[child] > a[parent])
		{
			//HPDataType temp=a[child];
			//a[child]=a[parent];
			//a[parent]=temp;
			Swap(&a[child],&a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//插入相当于尾插
void HeapPush(HP* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		//扩容
		int Newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* newNode = (HPDataType*)realloc(hp->a,sizeof(HPDataType) * Newcapacity);
		if (newNode == NULL)
		{
			printf("realloc false");
			exit(-1);
		}
		hp->a = newNode;
		hp->capacity = Newcapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	//传的是总共用了多少空间，和孩子的下标
	AdjustUp(hp->a, hp->size - 1);
}
//判读是否为空
bool HeapEmpty(HP* hp)
{
	//为空返回真true，为假返回false
	assert(hp);
	return hp->size == 0;
}
//找有效的个数
int HeapSize(HP* hp)
{
	return hp->size;
}
//向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	//小堆的向下调整
	assert(a);
	int child = parent * 2 + 1;
	//int leftchild = parent * 2 + 1;
	//int rightchild = parent * 2 + 2;
	//循环判断条件
	//while(leftchild<n && a[parent]>leftchild && a[parent]>rightchild)
	while (child < n)
	{
		//先找左孩子，然后看右孩子是否小于左孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
		//先比较左右孩子的大小，然后决定换哪里(不好)
		/*if(rightchild>=n)
		{
			Swap(&a[leftchild],&a[parent]);
			break;
		}
		if(a[leftchild]<a[rightchild])
		{
			//如果是左边小于右边，那么就跟左边交换
			Swap(&a[leftchild],&a[parent]);
			parent=leftchild;
			leftchild=parent*2+1;
			rightchild=parent*2+2;
		}
		else
		{
			Swap(&a[rightchild],&a[parent]);
			parent=rightchild;
			leftchild=parent*2+1;
			rightchild=parent*2+2;
		}*/
	}
}
//删除是从上往下删除
void HeapPop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&(hp->a[0]), &(hp->a[hp->size - 1]));
	hp->size--;
	AdjustDown(hp->a,hp->size, 0);
}
//销毁函数
void HeapDistroy(HP* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
//打印函数
void HeapPrint(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}