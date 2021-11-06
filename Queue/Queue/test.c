#include "Queue.h"

void test1()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	QueuePush(q, 4);
	QueuePop(q);
	QueuePop(q);
	QueuePop(q);
	//QueuePop(q);
//	QueuePop(q);
}
void test2()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	QueuePush(q, 4);
	printf("%d    %d", QueueFront(q), QueueBack(q));
}
void test3()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	QueuePush(q, 4);
	printf("%d ", QueueSize(q));
	QueueDestroy(q);
}

int main()
{
	//test1();
	//test2();
	test3();
}
