#include"Stack.h"
//判断栈空
//检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == -1;
}
// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->capacity = 0;
	ps->top = -1;
	ps->a = NULL;
}
//扩容
STDataType* BuyIntspace(Stack* ps)
{
	assert(ps);
	//判断如果capacity小于等于0就是设初始值为4，大于0就是开辟二倍
	STDataType Newcapacity = ps->capacity > 0 ? ps->capacity * 2 : 4;
	STDataType* temp = (STDataType*)realloc(ps->a,sizeof(STDataType)*Newcapacity);
	if (temp == NULL)
	{
		printf("realloc false\n");
		exit(-1);
	}
	ps->capacity = Newcapacity;
	return temp;
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top < 0 || ps->top == ps->capacity)
	{
		ps->a=BuyIntspace(ps);
	}
	//开始赋值,top从-1开始的
	ps->top++;
	ps->a[ps->top] = data;
}
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	//栈是先入的后出，后入的先出
	assert(!StackEmpty(ps));//空栈不能出
	ps->top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top + 1;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}