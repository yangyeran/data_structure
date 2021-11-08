#include "Heap.h"
void test1()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 70);
	HeapPush(&hp, 56);
	HeapPush(&hp, 30);
	HeapPush(&hp, 25);
	HeapPush(&hp, 15);
	HeapPush(&hp, 10);
	HeapPrint(&hp);
	HeapPush(&hp, 40);
	HeapPrint(&hp);
	HeapDistroy(&hp);
}
void test2()
{
	int n = 10000;
	int k = 10;
	int* a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		printf("malloc false\n");
		exit(-1);
	}
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = (rand()%100+1)*10000;//只有可能是0--9999
	}
	a[5] = a[5] / 10000;
	a[798] = a[798] / 10000;
	a[123] = a[123] / 10000;
	a[42] = a[42] / 10000;
	a[876] = a[876] / 10000;
	a[444] = a[444] / 10000;
	a[428] = a[428] / 10000;
	a[648] = a[648] / 10000;
	a[666] = a[666] / 10000;
	a[98] = a[98] / 10000;
	PrintTopk(a,n,k);
	free(a);
}
int main()
{
	//test1();
	test2();
}