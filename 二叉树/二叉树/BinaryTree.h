#pragma once
//�������Ļ�������ʵ��
//��ʵ��Ŀ�ġ�
//1���������������ĸ��
//2�����ն������������������������ͺ�������ĸ����㷨��
//��ʵ�����ݡ�
//��д����traversebinarytree.cpp��ʵ�ֶ������������������������ͺ�������ĸ��ֵݹ��㷨��
//���ο����롿
//����traversebinarytree.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node {	//����������ڵ�
	ElemType data;
	struct node* lchild;
	struct node* rchild;
} BTNode;

//��str������������
void CreateBTNode(BTNode*& b, char* str);
//�Թ������ʽ�����ű�ʾ�������������
void DispBTNode(BTNode* b);
//�ͷŶ�����
void DestroyBTNode(BTNode*& b);
//��������ĵݹ��㷨
void PreOrder(BTNode* b);
//��������ĵݹ��㷨
void InOrder(BTNode* b);
//��������ĵݹ��㷨
void PostOrder(BTNode* b);