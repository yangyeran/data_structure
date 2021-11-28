//实验二  栈的基本运算
//【实验目的】
//1．掌握栈的链式存储表示。
//2．掌握链栈的基本操作，包括创建、入栈、出栈等算法。
//【实验内容】
//编写程序linkstack.cpp，实现链栈的各种基本运算（假设栈中的元素类型为char），完成如下功能：
//1．初始化栈；
//2．判断栈是否为空；
//3．依次入栈元素a，b，c，d，e；
//4．判断栈是否为空；
//5．输出出栈序列；
//6．判断栈是否为空；
//7．释放栈。
//【参考代码】
//程序linkstack.cpp
#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct linknode {		//定义链栈
	ElemType data;				//数据域
	struct linknode* next;		//指针域
} LiStack;

void InitStack(LiStack*& s) {		//初始化栈
	LiStack* head = (LiStack*)malloc(sizeof(LiStack));//给一个头指针
	head->next = NULL;//置空
	s = head;
}
void DestroyStack(LiStack*& s) {	//销毁栈
	LiStack* p = s, * q = s->next;
	while (q != NULL) {
		free(p);
		p = q;
		q = p->next;
	}
	free(p);		//此时p指向尾节点，释放其空间
}
bool StackEmpty(LiStack* s) {		//判断栈是否为空
	return (s->next == NULL);
}
void Push(LiStack*& s, ElemType e) {	//进栈
	LiStack* p;//头插
	p = (LiStack*)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
void Push1()
{
}
bool Pop(LiStack*& s, ElemType& e) {	//出栈
	LiStack* p;
	p = s->next;
	if (s->next == NULL)		//栈空的情况
		return false;
	//因为是头插所以只需要从头开始出就好
	e = p->data;
	s->next = s->next->next;
	free(p);
	return true;
}
bool GetTop(LiStack* s, ElemType& e) {	//取栈顶元素
	if (s->next == NULL)		//栈空的情况
		return false;
	e = s->next->data;
	return true;
}

int main() {
	ElemType e;
	LiStack* s;
	printf("链栈的基本运算如下：\n");
	printf("  1．初始化栈\n");
	InitStack(s);
	printf("  2．栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  3．依次进栈元素a、b、c、d、e\n");
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	Push(s, 'e');
	printf("  4．栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  5．出栈序列：");
	while (!StackEmpty(s))
	{
		Pop(s, e);
		printf("%c ", e);
	}
	printf("\n");
	printf("  6．栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  7．释放栈\n");
	DestroyStack(s);
	return 0;
}

