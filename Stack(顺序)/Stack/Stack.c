#include"Stack.h"
//�ж�ջ��
//���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == -1;
}
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->capacity = 0;
	ps->top = -1;
	ps->a = NULL;
}
//����
STDataType* BuyIntspace(Stack* ps)
{
	assert(ps);
	//�ж����capacityС�ڵ���0�������ʼֵΪ4������0���ǿ��ٶ���
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
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top < 0 || ps->top == ps->capacity)
	{
		ps->a=BuyIntspace(ps);
	}
	//��ʼ��ֵ,top��-1��ʼ��
	ps->top++;
	ps->a[ps->top] = data;
}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	//ջ������ĺ����������ȳ�
	assert(!StackEmpty(ps));//��ջ���ܳ�
	ps->top--;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top + 1;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}