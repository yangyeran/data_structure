#include "BinaryTree.h"
//求节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right) + 1;
}
//求叶子节点的个数
//叶子节点的特点是左右子树都为空
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == root->right)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
//二叉树第k层节点个数
int BinaryTreeLevelkSize(BTNode* root, int k)
{
	//如果k=1，那就是本层
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//遍历左右子树将结果加起来
	return BinaryTreeLevelkSize(root->left,k-1) + BinaryTreeLevelkSize(root->right, k - 1);
}

//二叉树深度/高度
int BinaryTreeDepth(BTNode* root)
{
	//先左右子树比较，长的加1就是高度
	if (root == NULL)
		return 0;
	//需要用个值来储存，如果不储存的话会产生大量的重复计算
	int leftret = BinaryTreeDepth(root->left);
	int rightret = BinaryTreeDepth(root->right);
	return leftret > rightret ? leftret + 1 : rightret + 1;
}
//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//首先root为空就不进行了
	//其次就是相当于遍历一边左右子树，同时比较一下的值，一样返回当前节点，不一样往后走
	//直到走到结束
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