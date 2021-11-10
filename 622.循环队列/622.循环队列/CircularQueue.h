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
//初始化
void MyCircularQueueInit(MyCircularQueue** QHead);
//创建
MyCircularQueue* myCircularQueueCreate(int k);
//插入
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
//删除元素
bool myCircularQueueDeQueue(MyCircularQueue* obj);
//队首元素
int myCircularQueueFront(MyCircularQueue* obj);
//队尾元素
int myCircularQueueRear(MyCircularQueue* obj);
//判断满不满
bool myCircularQueueIsFull(MyCircularQueue* obj);
//判断是不是非空队列
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//销毁队列
void myCircularQueueFree(MyCircularQueue* obj);
