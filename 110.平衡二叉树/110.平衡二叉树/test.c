#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 

int MaxDepth(struct TreeNode* root)
{
    //求深度
    if (root == NULL)
        return 0;
    int leftret = MaxDepth(root->left);
    int rightret = MaxDepth(root->right);
    return leftret > rightret ? leftret + 1 : rightret + 1;
}
bool isBalanced(struct TreeNode* root) {
    //算出各个节点的最大深度
    //比较
    if (root == NULL)
        return true;
    int left = MaxDepth(root->left);
    int right = MaxDepth(root->right);
    //平衡二叉树是每一个节点的深度都不能超过1，不只是根节点的左右子树深度不超过1
    //所以需要后面的继续递归
    return (abs(left - right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}