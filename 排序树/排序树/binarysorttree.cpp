//�����������Ļ�������
//��ʵ�����ݡ�
//��д����ʵ�ֶ����������Ļ������㣬���ڴ˻�����������¹��ܣ�
//1����{ 4,9,0,1,8,6,3,5,2,7 }����һ�ö������������������ű�ʾ�������
//2���ж������������Ƿ�Ϊ������������
//3�����õݹ�ͷǵݹ����ַ������ҹؼ���Ϊ6�Ľڵ㣬���������·����
//4���ֱ�ɾ�������������йؼ���Ϊ4��5�Ľڵ㣬�����������������
//���ο����롿
//����binarysorttree.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;					//����ؼ�������
typedef char InfoType;
typedef struct node {	//��¼����
	KeyType key;             		//�ؼ�����
	InfoType data;          		//����������
	struct node* lchild, * rchild;		//���Һ���ָ��
} BSTNode;
int path[MaxSize];					//ȫ�ֱ��������ڴ��·��
void DispBST(BSTNode* b);			//����������ʵ���ں���
//����*pΪ���ڵ��BST�в���һ���ؼ���Ϊk�Ľڵ�
int InsertBST(BSTNode*& p, KeyType k) {
	if (p == NULL) {				//ԭ��Ϊ�գ��²���ļ�¼Ϊ���ڵ�
		p = (BSTNode*)malloc(sizeof(BSTNode));
		p->key = k; p->lchild = p->rchild = NULL;
		return 1;
	}
	else if (k == p->key)
		return 0;
	else if (k < p->key)
		return InsertBST(p->lchild, k);
	else
		return InsertBST(p->rchild, k);

}
BSTNode* CreatBST(KeyType A[], int n) {	//������A�еĹؼ��ֽ���һ�ö���������
	BSTNode* bt = NULL;         		//��ʼʱbtΪ����
	int i = 0;
	while (i < n)
		if (InsertBST(bt, A[i]) == 1) {	//��A[i]�������������T��
			printf("    ��%d��������%d��", i + 1, A[i]);
			DispBST(bt);
			printf("\n");
			i++;
		}
	return bt;               	//���ؽ����Ķ����������ĸ�ָ��
}
void Delete1(BSTNode* p, BSTNode*& r) {	//����ɾ*p�ڵ�����������ʱ��ɾ������
	BSTNode* q;
	if (r->rchild != NULL)
		Delete1(p, r->rchild);		//�ݹ��������½ڵ�
	else {						//�ҵ��������½ڵ�*r
		p->key = r->key;	//��*r�Ĺؼ���ֵ����*p
		q = r;
		r = r->lchild;	//��*r��˫�׽ڵ���Һ��ӽڵ��Ϊ*r�����ӽڵ�
		free(q);		//�ͷ�ԭ*r�Ŀռ�
	}
}
void Delete(BSTNode*& p) {		//�Ӷ�����������ɾ��*p�ڵ�
	BSTNode* q;
	if (p->rchild == NULL) {			//*p�ڵ�û�������������
		q = p; p = p->lchild; free(q);
	}
	else if (p->lchild == NULL) {		//*p�ڵ�û�������������
		q = p; p = p->rchild; free(q);
	}
	else						//*p�ڵ�������������������������
		Delete1(p, p->lchild);
}
int DeleteBST(BSTNode*& bt, KeyType k) {		//��bt��ɾ���ؼ���Ϊk�Ľڵ�
	if (bt == NULL)		//����ɾ��ʧ��
		return 0;
	else {
		if (k < bt->key)
			return DeleteBST(bt->lchild, k); //�ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
		else if (k > bt->key)
			return DeleteBST(bt->rchild, k); //�ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
		else {				//k=bt->key�����
			Delete(bt);
			return 1;
		}
	}
}
//�Էǵݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
void SearchBST1(BSTNode* bt, KeyType k, KeyType path[], int i) {
	int j;
	if (bt == NULL)
		return;
	else if (k == bt->key) {		//�ҵ��˽ڵ�
		path[i + 1] = bt->key;	//�����·��
		for (j = 0; j <= i + 1; j++)
			printf("%3d", path[j]);
		printf("\n");
	}
	else {
		path[i + 1] = bt->key;
		if (k < bt->key)
			SearchBST1(bt->lchild, k, path, i + 1);  //���������еݹ����
		else
			SearchBST1(bt->rchild, k, path, i + 1);  //���������еݹ����
	}
}
//�Եݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
int SearchBST2(BSTNode* bt, KeyType k) {
	if (bt == NULL)
		return 0;
	else if (k == bt->key) {
		printf("%3d", bt->key);
		return 1;
	}
	else if (k < bt->key)
		SearchBST2(bt->lchild, k);  //���������еݹ����
	else
		SearchBST2(bt->rchild, k);  //���������еݹ����
	printf("%3d", bt->key);
}
void DispBST(BSTNode* bt) {		//�����ű�ʾ���������������bt
	if (bt != NULL) {
		printf("%d", bt->key);
		if (bt->lchild != NULL || bt->rchild != NULL) {
			printf("(");
			DispBST(bt->lchild);
			if (bt->rchild != NULL)
				printf(",");
			DispBST(bt->rchild);
			printf(")");
		}
	}
}
KeyType predt = -32767;	//ȫ�ֱ��������浱ǰ�ڵ�����ǰ����ֵ����ֵΪ-��
int JudgeBST(BSTNode* bt) {		//�ж�bt�Ƿ�ΪBST
	int b1, b2;
	if (bt == NULL)
		return 1;
	else {
		b1 = JudgeBST(bt->lchild);
		if (b1 == 0 || predt >= bt->key)
			return 0;
		predt = bt->key;
		b2 = JudgeBST(bt->rchild);
		return b2;
	}
}
//������� 
int main() {
	BSTNode* bt;
	KeyType k = 6;
	int a[] = { 4,9,0,1,8,6,3,5,2,7 }, n = 10;
	printf("����һ��BST����\n");
	bt = CreatBST(a, n);
	printf("������������");
	DispBST(bt);
	printf("\n");
	printf("����%s\n", (JudgeBST(bt) ? "��һ��BST" : "����һ��BST"));
	printf("   ����%d�ؼ���(�ݹ飬˳��)��", k);
	SearchBST1(bt, k, path, -1);
	printf("   ����%d�ؼ���(�ǵݹ飬����)��", k);
	SearchBST2(bt, k);
	printf("\nɾ��������\n");
	printf("   ԭBST��");
	DispBST(bt);
	printf("\n");
	printf("   ɾ���ڵ�4��");
	DeleteBST(bt, 4);
	DispBST(bt);
	printf("\n");
	printf("   ɾ���ڵ�5��");
	DeleteBST(bt, 5);
	DispBST(bt);
	printf("\n");
	return 0;
}