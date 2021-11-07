#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
//����ʵ�ֵ��Ǵ��
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
//��ʼ������
void HeapInit(HP* hp);
//���ٺ���
void HeapDistroy(HP* hp);
//��������
void Swap(HPDataType* hp, HPDataType* hy);

//�����ϵ���
void AdjustUp(HPDataType* a, int child);

//�����൱��β��
void HeapPush(HP* hp, HPDataType x);

//�ж��Ƿ�Ϊ��
bool HeapEmpty(HP* hp);

//���µ���
void AdjustDown(HPDataType* a, int n, int parent);

//ɾ���Ǵ�������ɾ��
void HeapPop(HP* hp);

//��ӡ����
void HeapPrint(HP* hp);

//�ҳ����˶�����
int HeapSize(HP* hp);