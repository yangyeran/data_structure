#include "BinaryTree.h"
#include"Queue.h"
void test1()//构建和销毁正常
{
	char str[] = "ABD##E#H##CF##G##";
	int i = 0;
	int size = sizeof(str);
	BTNode*root=BinaryTreeCreate(str, size, &i);
	BinaryTreeDestory(&root);
}
void test2()
{
	char str[] = "ABD##E##C##";//"ABD##E#H##CF##G##";
	int i = 0;
	int size = sizeof(str);
	BTNode* root = BinaryTreeCreate(str, size, &i);
	int TreeNode=BinaryTreeSize(root);
	int TreeLeaf=BinaryTreeLeafSize(root);
	int TreeLeve = BinaryTreeLevelKSize(root, 3);
	int Complete = BinaryTreeComplete(root);
	int Depth = BinaryTreeDepth(root);
	BTNode* TreeFind = BinaryTreeFind(root, 'E');
	printf("TreeNode:  %d\n", TreeNode);
	printf("TreeLeaf:  %d\n", TreeLeaf);
	printf("TreeLeve:  %d\n", TreeLeve);
	printf("Complete:  %d\n", Complete);
	printf("Depth   :  %d\n", Depth);
	printf("TreeFind:  %p\n", TreeFind);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	BinaryTreeDestory(&root);
}
int main()
{
	//test1();
	test2();
}