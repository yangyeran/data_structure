#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//��ڵ����
int BinaryTreeLeafSize(BTNode* root);
//��Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
//��������k��ڵ����
int BinaryTreeLevelkSize(BTNode* root, int k);
//���������/�߶�
int BinaryTreeDepth(BTNode* root);
//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);