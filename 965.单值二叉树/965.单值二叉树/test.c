#include<stdio.h>
#include<stdbool.h>
  struct TreeNode {
      int val;
     struct TreeNode *left;
      struct TreeNode *right;
  };
 


bool isUnivalTree(struct TreeNode* root) {
    //�Ƚ����ҵ������ڵ�����ڵ��಻��ͬ
    if (root == NULL)
        return true;
    if (root->left && root->val != root->left->val)
        return false;
    if (root->right && root->val != root->right->val)
        return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}