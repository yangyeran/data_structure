#include "BinaryTree.h"
#include"Queue.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] != '#'&&(*pi)<n)
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		if (root == NULL)
			exit(-1);
		root->data = a[*pi];
		//++��*�����ȼ���ͬ����������
		++(*pi);
		root->left = BinaryTreeCreate(a, n, pi);
		++(*pi);
		root->right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	else
		return NULL;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	//����ֱ�Ӿ��Ǻ����������
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);
	*root = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	//�ڵ�������Ǳ���һ�߾ͺ�
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	//��ڵ�ı���
	//Ҷ�ӽڵ���ص�������ҽڵ㶼Ϊ��
	if (root == NULL)
		return 0;
	if (root->left == root->right)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//��k��ڵ���������Կ��ɵ�һ���ǵ�һ�㣬Ȼ��k���ϵݼ�ȥ��k=1���ǲ㣬������ڵ������
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//����˼·���Ǳ����������ڱ��������������ǰ�ҵ��ͷ��ؽڵ㣬����ߵ����û�оͷ���NULL
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	//����ֻҪ��һ���ҵ��ͷ������ڵĵ�ַ���������Ҳ������ؿ�
	BTNode* LeftRet = BinaryTreeFind(root->left, x);
	if (LeftRet)
		return LeftRet;
	BTNode* RightRet = BinaryTreeFind(root->right, x);
	if (RightRet)
		return RightRet;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	//�ȴ�ӡ���ٴ�ӡ���ҽڵ�
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
//���������������
void BinaryTreeInOrder(BTNode* root)
{
	//�ȴ�ӡ��ڵ㣬�ڴ�ӡ�����ҽڵ�
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
//�������ĺ������
void BinaryTreePostOrder(BTNode* root)
{
	//�ȴ�ӡ���ҽڵ��ڴ�ӡ���ڵ�
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	//1.�����������Ҫ�ݹ飬����ͨ��������ʵ��
	//2.��һ���ڵ�ʹ����������Һ���(��Ҫ�����жϺ����Ƿ�Ϊ��)
	//3.��һ���ʹ�ӡһ��
	Queue* q=(Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	QueuePush(q, root);
	BTNode* cur = NULL;
	while (!QueueEmpty(q))
	{
		cur = QueueFront(q);
		QueuePop(q);
		printf("%c ", cur->data);
		if(cur->left)
		QueuePush(q, cur->left);
		if(cur->right)
		QueuePush(q, cur->right);
	}
	//���о�Ϊ����
	QueueDestroy(q);
}
//���������/�߶�
int BinaryTreeDepth(BTNode* root)
{
	//�����������Ƚϣ����ļ�1���Ǹ߶�
	if (root == NULL)
		return 0;
	//��Ҫ�ø�ֵ�����棬���������Ļ�������������ظ�����
	int leftret = BinaryTreeDepth(root->left);
	int rightret = BinaryTreeDepth(root->right);
	return leftret > rightret ? leftret + 1 : rightret + 1;
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	//��ȫ���������ж��õĻ��ǲ��������˼��
	//Ϊ��ȫ����������˵������NULL��ʱ�򣬾�����ѭ����ʼ����һ�����
	//�����������ȫ��NULL��ô������ȫ������
	//����в�ΪNULL�ľ��Ƿ���ȫ������
	//��ȫ����������1������ȫ����������0
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	QueuePush(q, root);
	while (!QueueEmpty(q))
	{
		BTNode* cur = QueueFront(q);
		QueuePop(q);
		//���Һ���Ϊ��Ҳ������
		if (cur != NULL)
		{
			QueuePush(q, cur->left);
			QueuePush(q, cur->right);
		}
		else
			break;
	}
	//�ߵ����������ֿ����ԣ�һ���Ƕ���Ϊ���ˣ���ȫ��������
	//��һ�־��Ƕ��в�Ϊ�գ�����һ�߶���;
	while (!QueueEmpty(q))
	{
		BTNode* cur = QueueFront(q);
		QueuePop(q);
		if (cur != NULL)
		{
			QueueDestroy(q);
			return 0;
		}
	}
	QueueDestroy(q);
	return 1;
}