#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<time.h>
//这里实现的是大堆
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
//初始化函数
void HeapInit(HP* hp);
// 堆的构建
void HeapCreate(HP* hp, HPDataType* a, int n);
//销毁函数
void HeapDistroy(HP* hp);
//交换函数
void Swap(HPDataType* hp, HPDataType* hy);

//堆向上调整
void AdjustUp(HPDataType* a, int child);

//插入相当于尾插
void HeapPush(HP* hp, HPDataType x);

//判断是否为空
bool HeapEmpty(HP* hp);

//向下调整
void AdjustDown(HPDataType* a, int n, int parent);

//删除是从上往下删除
void HeapPop(HP* hp);

//打印函数
void HeapPrint(HP* hp);

//找出存了多少数
int HeapSize(HP* hp);

//Topk算法
void HeapTopk(HPDataType* a, int n, int k);

//查找顶端
int HeapTop(HP* hp);