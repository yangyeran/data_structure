#include "BinaryTree.h"
//������� 
int main() {
	BTNode* b;
	char btc[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
	CreateBTNode(b, btc);
	printf("��������");
	DispBTNode(b);
	printf("\n");
	printf("����������У�\n");
	PreOrder(b);
	printf("\n");
	printf("����������У�\n");
	InOrder(b);
	printf("\n");
	printf("����������У�\n");
	PostOrder(b);
	printf("\n");
	DestroyBTNode(b);
	return 0;
}


