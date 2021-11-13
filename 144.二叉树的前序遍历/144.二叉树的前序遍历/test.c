#include<stdio.h>
#include<stdlib.h>
//returnSize是力扣上给的返回值，返回的是数组总大小
//要求返回最后malloc开辟出来的数组首元素地址
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
  //计算树中有多少个节点
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
//前序遍历将节点存在开辟的数组中
void _preorderTraversal(struct TreeNode* root, int* Treenode, int* pi)
{
    if (root == NULL)
        return;
    //要考虑优先级
    Treenode[(*pi)++] = root->val;
    _preorderTraversal(root->left, Treenode, pi);
    _preorderTraversal(root->right, Treenode, pi);
}
//主体函数
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* Treenode = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _preorderTraversal(root, Treenode, &i);
    return Treenode;
}