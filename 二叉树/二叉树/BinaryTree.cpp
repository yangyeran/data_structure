#include"BinaryTree.h"
void CreateBTNode(BTNode*& b, char* str) {	//由str串创建二叉链
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//建立的二叉树初始时为空
	ch = str[j];
	while (ch != '\0') {		//str未扫描完时循环
		switch (ch) {
		case '(':		//为左节点
			top++;
			St[top] = p;  //  记录后续结点的父结点地址  A  B
			k = 1;//k作为左右孩子标记 1  左孩子  2  右孩子
			break;
		case ')':		//为右节点
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)          	//p指向二叉树的根节点
				b = p;
			else {  					//已建立二叉树根节点
				switch (k) {
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
void DispBTNode(BTNode* b) {	//以广义表形式（括号表示法）输出二叉树
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");
			DispBTNode(b->lchild);
			if (b->rchild != NULL)
				printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
	}
}
void DestroyBTNode(BTNode*& b) {	//释放二叉树
	if (b != NULL) {
		DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}
void PreOrder(BTNode* b) {	//先序遍历的递归算法
	if (b != NULL) {
		printf("%c ", b->data);	//访问根节点
		PreOrder(b->lchild);	//递归访问左子树
		PreOrder(b->rchild);	//递归访问右子树
	}
}

void InOrder(BTNode* b) {	//中序遍历的递归算法
	if (b != NULL) {
		InOrder(b->lchild);		//递归访问左子树
		printf("%c ", b->data);		//访问根节点
		InOrder(b->rchild);		//递归访问右子树
	}
}

void PostOrder(BTNode* b) {		//后序遍历的递归算法
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ", b->data);
	}
}