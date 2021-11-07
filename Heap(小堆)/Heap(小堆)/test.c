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
int main()
{
	test1();
}