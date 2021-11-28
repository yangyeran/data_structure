//ʵ���  ջ�Ļ�������
//��ʵ��Ŀ�ġ�
//1������ջ����ʽ�洢��ʾ��
//2��������ջ�Ļ���������������������ջ����ջ���㷨��
//��ʵ�����ݡ�
//��д����linkstack.cpp��ʵ����ջ�ĸ��ֻ������㣨����ջ�е�Ԫ������Ϊchar����������¹��ܣ�
//1����ʼ��ջ��
//2���ж�ջ�Ƿ�Ϊ�գ�
//3��������ջԪ��a��b��c��d��e��
//4���ж�ջ�Ƿ�Ϊ�գ�
//5�������ջ���У�
//6���ж�ջ�Ƿ�Ϊ�գ�
//7���ͷ�ջ��
//���ο����롿
//����linkstack.cpp
#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct linknode {		//������ջ
	ElemType data;				//������
	struct linknode* next;		//ָ����
} LiStack;

void InitStack(LiStack*& s) {		//��ʼ��ջ
	LiStack* head = (LiStack*)malloc(sizeof(LiStack));//��һ��ͷָ��
	head->next = NULL;//�ÿ�
	s = head;
}
void DestroyStack(LiStack*& s) {	//����ջ
	LiStack* p = s, * q = s->next;
	while (q != NULL) {
		free(p);
		p = q;
		q = p->next;
	}
	free(p);		//��ʱpָ��β�ڵ㣬�ͷ���ռ�
}
bool StackEmpty(LiStack* s) {		//�ж�ջ�Ƿ�Ϊ��
	return (s->next == NULL);
}
void Push(LiStack*& s, ElemType e) {	//��ջ
	LiStack* p;//ͷ��
	p = (LiStack*)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
void Push1()
{
}
bool Pop(LiStack*& s, ElemType& e) {	//��ջ
	LiStack* p;
	p = s->next;
	if (s->next == NULL)		//ջ�յ����
		return false;
	//��Ϊ��ͷ������ֻ��Ҫ��ͷ��ʼ���ͺ�
	e = p->data;
	s->next = s->next->next;
	free(p);
	return true;
}
bool GetTop(LiStack* s, ElemType& e) {	//ȡջ��Ԫ��
	if (s->next == NULL)		//ջ�յ����
		return false;
	e = s->next->data;
	return true;
}

int main() {
	ElemType e;
	LiStack* s;
	printf("��ջ�Ļ����������£�\n");
	printf("  1����ʼ��ջ\n");
	InitStack(s);
	printf("  2��ջΪ%s\n", (StackEmpty(s) ? "��" : "�ǿ�"));
	printf("  3�����ν�ջԪ��a��b��c��d��e\n");
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	Push(s, 'e');
	printf("  4��ջΪ%s\n", (StackEmpty(s) ? "��" : "�ǿ�"));
	printf("  5����ջ���У�");
	while (!StackEmpty(s))
	{
		Pop(s, e);
		printf("%c ", e);
	}
	printf("\n");
	printf("  6��ջΪ%s\n", (StackEmpty(s) ? "��" : "�ǿ�"));
	printf("  7���ͷ�ջ\n");
	DestroyStack(s);
	return 0;
}

