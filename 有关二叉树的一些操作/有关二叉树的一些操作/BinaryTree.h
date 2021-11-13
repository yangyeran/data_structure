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

//求节点个数
int BinaryTreeLeafSize(BTNode* root);
//求叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
//二叉树第k层节点个数
int BinaryTreeLevelkSize(BTNode* root, int k);
//二叉树深度/高度
int BinaryTreeDepth(BTNode* root);
//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);