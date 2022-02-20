#include "BinaryTree.h"
//程序入口 
int main() {
	BTNode* b;
	char btc[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
	CreateBTNode(b, btc);
	printf("二叉树：");
	DispBTNode(b);
	printf("\n");
	printf("先序遍历序列：\n");
	PreOrder(b);
	printf("\n");
	printf("中序遍历序列：\n");
	InOrder(b);
	printf("\n");
	printf("后序遍历序列：\n");
	PostOrder(b);
	printf("\n");
	DestroyBTNode(b);
	return 0;
}


