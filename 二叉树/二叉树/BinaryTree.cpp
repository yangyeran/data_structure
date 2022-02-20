#include"BinaryTree.h"
void CreateBTNode(BTNode*& b, char* str) {	//��str������������
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//�����Ķ�������ʼʱΪ��
	ch = str[j];
	while (ch != '\0') {		//strδɨ����ʱѭ��
		switch (ch) {
		case '(':		//Ϊ��ڵ�
			top++;
			St[top] = p;  //  ��¼�������ĸ�����ַ  A  B
			k = 1;//k��Ϊ���Һ��ӱ�� 1  ����  2  �Һ���
			break;
		case ')':		//Ϊ�ҽڵ�
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)          	//pָ��������ĸ��ڵ�
				b = p;
			else {  					//�ѽ������������ڵ�
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
void DispBTNode(BTNode* b) {	//�Թ������ʽ�����ű�ʾ�������������
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
void DestroyBTNode(BTNode*& b) {	//�ͷŶ�����
	if (b != NULL) {
		DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}
void PreOrder(BTNode* b) {	//��������ĵݹ��㷨
	if (b != NULL) {
		printf("%c ", b->data);	//���ʸ��ڵ�
		PreOrder(b->lchild);	//�ݹ����������
		PreOrder(b->rchild);	//�ݹ����������
	}
}

void InOrder(BTNode* b) {	//��������ĵݹ��㷨
	if (b != NULL) {
		InOrder(b->lchild);		//�ݹ����������
		printf("%c ", b->data);		//���ʸ��ڵ�
		InOrder(b->rchild);		//�ݹ����������
	}
}

void PostOrder(BTNode* b) {		//��������ĵݹ��㷨
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ", b->data);
	}
}