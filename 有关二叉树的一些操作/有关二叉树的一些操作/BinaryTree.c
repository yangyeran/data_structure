#include "BinaryTree.h"
//��ڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right) + 1;
}
//��Ҷ�ӽڵ�ĸ���
//Ҷ�ӽڵ���ص�������������Ϊ��
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == root->right)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
//��������k��ڵ����
int BinaryTreeLevelkSize(BTNode* root, int k)
{
	//���k=1���Ǿ��Ǳ���
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//�����������������������
	return BinaryTreeLevelkSize(root->left,k-1) + BinaryTreeLevelkSize(root->right, k - 1);
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
//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//����rootΪ�վͲ�������
	//��ξ����൱�ڱ���һ������������ͬʱ�Ƚ�һ�µ�ֵ��һ�����ص�ǰ�ڵ㣬��һ��������
	//ֱ���ߵ�����
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* reftret=BinaryTreeFind(root->left,x);
	if (reftret)
		return reftret;
	BTNode* rightret=BinaryTreeFind(root->right, x);
	if (rightret)
		return rightret;
	return NULL;
}