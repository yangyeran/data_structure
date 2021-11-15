#include<stdio.h>
#include<stdlib.h>
  struct TreeNode 
  {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _inorderTraversal(struct TreeNode* root, int* Treenode, int* pi)
{
    if (root == NULL)
        return;
    //中序遍历，先左 在中 后右
    _inorderTraversal(root->left, Treenode, pi);
    Treenode[(*pi)++] = root->val;
    _inorderTraversal(root->right, Treenode, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* Treenode = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _inorderTraversal(root, Treenode, &i);
    return Treenode;
}