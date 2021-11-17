#include "BinaryTree.h"
#include"Queue.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] != '#'&&(*pi)<n)
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		if (root == NULL)
			exit(-1);
		root->data = a[*pi];
		//++和*的优先级相同，从右向左
		++(*pi);
		root->left = BinaryTreeCreate(a, n, pi);
		++(*pi);
		root->right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	else
		return NULL;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	//销毁直接就是后序遍历销毁
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);
	*root = NULL;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	//节点个数就是遍历一边就好
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	//求节点的变形
	//叶子节点的特点就是左右节点都为空
	if (root == NULL)
		return 0;
	if (root->left == root->right)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//求k层节点个数，可以看成第一层是第一层，然后k不断递减去找k=1的那层，计算出节点个数；
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//主体思路就是遍历左树后在遍历右树，如果提前找到就返回节点，如果走到最后都没有就返回NULL
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	//两个只要有一个找到就返回所在的地址，两个都找不到返回空
	BTNode* LeftRet = BinaryTreeFind(root->left, x);
	if (LeftRet)
		return LeftRet;
	BTNode* RightRet = BinaryTreeFind(root->right, x);
	if (RightRet)
		return RightRet;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	//先打印根再打印左右节点
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
//二叉树的中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	//先打印左节点，在打印根和右节点
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
//二叉树的后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	//先打印左右节点在打印根节点
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	//1.层序遍历不需要递归，可以通过队列来实现
	//2.出一个节点就带入它的左右孩子(需要进行判断孩子是否为空)
	//3.出一个就打印一个
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
	//队列就为空了
	QueueDestroy(q);
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
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	//完全二叉树的判断用的还是层序遍历的思想
	//为完全二叉树就是说当出到NULL的时候，就跳出循环开始遍历一遍队列
	//如果队列里面全是NULL那么就是完全二叉树
	//如果有不为NULL的就是非完全二叉树
	//完全二叉树返回1，非完全二叉树返回0
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	QueuePush(q, root);
	while (!QueueEmpty(q))
	{
		BTNode* cur = QueueFront(q);
		QueuePop(q);
		//左右孩子为空也进队列
		if (cur != NULL)
		{
			QueuePush(q, cur->left);
			QueuePush(q, cur->right);
		}
		else
			break;
	}
	//走到这里有两种可能性，一种是队列为空了（完全二叉树）
	//另一种就是队列不为空，遍历一边队列;
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