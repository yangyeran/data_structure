#pragma once
//二叉树的基本操作实现
//【实验目的】
//1．理解二叉树遍历的概念。
//2．掌握二叉树的先序遍历、中序遍历和后序遍历的各种算法。
//【实验内容】
//编写程序traversebinarytree.cpp，实现二叉树的先序遍历、中序遍历和后序遍历的各种递归算法。
//【参考代码】
//程序traversebinarytree.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node {	//定义二叉树节点
	ElemType data;
	struct node* lchild;
	struct node* rchild;
} BTNode;

//由str串创建二叉链
void CreateBTNode(BTNode*& b, char* str);
//以广义表形式（括号表示法）输出二叉树
void DispBTNode(BTNode* b);
//释放二叉树
void DestroyBTNode(BTNode*& b);
//先序遍历的递归算法
void PreOrder(BTNode* b);
//中序遍历的递归算法
void InOrder(BTNode* b);
//后序遍历的递归算法
void PostOrder(BTNode* b);