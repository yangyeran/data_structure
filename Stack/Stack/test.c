#include"Stack.h"
void test1()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps,1);
	StackPush(&ps, 2);
	StackPush(&ps,3);
	StackPop(&ps);
	StackPop(&ps);
	printf("%d ",StackTop(&ps));
	//StackPop(&ps);
}
int main()
{
	test1();
}