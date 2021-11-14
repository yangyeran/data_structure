#include<stdio.h>
#include<stdlib.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _postorderTraversal(struct TreeNode* root, int* Treenode, int* pi)
{
    if (root == NULL)
        return;
    //中序遍历，先左 在右 后根
    _postorderTraversal(root->left, Treenode, pi);
    _postorderTraversal(root->right, Treenode, pi);
    Treenode[(*pi)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* Treenode = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _postorderTraversal(root, Treenode, &i);
    return Treenode;
}