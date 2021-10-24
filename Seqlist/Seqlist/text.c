# define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void test1()//ok
{
	SeqList ps;
	SeqListInit(&ps);
	SeqListPushFront(&ps,1);
	SeqListPushFront(&ps,3);
	SeqListPushFront(&ps,4);
	SeqListPrint(&ps);
	printf("\n%d\n",SeqListFind(&ps,3));
	SeqListDestory(&ps);
}
void test2()//ok
{
	SeqList ps;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushFront(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPrint(&ps);
	SeqListDestory(&ps);
}
void test3()
{
	SeqList ps;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPrint(&ps);//1 2 3 4
	//SeqListErase(&ps, 2);
	//SeqListErase(&ps, 3);
	SeqListPopFront(&ps);
	SeqListPopFront(&ps);
	printf("\n");
	SeqListPrint(&ps);
	SeqListDestory(&ps);
}
int main()
{
	test1();
	//test2();
	//test3();

}