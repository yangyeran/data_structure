#include "CircularQueue.h"
void test1()
{
	MyCircularQueue* circularQueue= myCircularQueueCreate(3);
	printf("%d ",myCircularQueueEnQueue(circularQueue, 1));
	printf("%d ", myCircularQueueEnQueue(circularQueue,2));
	printf("%d ", myCircularQueueEnQueue(circularQueue,3));
	printf("%d ", myCircularQueueEnQueue(circularQueue,4));
	printf("%d ",myCircularQueueRear(circularQueue));
	printf("%d ",myCircularQueueIsFull(circularQueue));
	printf("%d ",myCircularQueueDeQueue(circularQueue));
	printf("%d ", myCircularQueueEnQueue(circularQueue, 4));
	printf("%d ", myCircularQueueRear(circularQueue));
}
int main()
{
	test1();
}