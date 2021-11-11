#include<stdio.h>
#include<stdbool.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftret = maxDepth(root->left);
    int rightret = maxDepth(root->right);
    return leftret > rightret ? leftret + 1 : rightret + 1;
}