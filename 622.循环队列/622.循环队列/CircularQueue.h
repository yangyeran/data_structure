#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QDataType;
typedef struct
{
    QDataType* a;
    int size;
    int capacity;
    int Head;
    int Tail;
} MyCircularQueue;
//��ʼ��
void MyCircularQueueInit(MyCircularQueue** QHead);
//����
MyCircularQueue* myCircularQueueCreate(int k);
//����
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
//ɾ��Ԫ��
bool myCircularQueueDeQueue(MyCircularQueue* obj);
//����Ԫ��
int myCircularQueueFront(MyCircularQueue* obj);
//��βԪ��
int myCircularQueueRear(MyCircularQueue* obj);
//�ж�������
bool myCircularQueueIsFull(MyCircularQueue* obj);
//�ж��ǲ��Ƿǿն���
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//���ٶ���
void myCircularQueueFree(MyCircularQueue* obj);
