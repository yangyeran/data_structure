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
    //�����
    if (root == NULL)
        return 0;
    int leftret = MaxDepth(root->left);
    int rightret = MaxDepth(root->right);
    return leftret > rightret ? leftret + 1 : rightret + 1;
}
bool isBalanced(struct TreeNode* root) {
    //��������ڵ��������
    //�Ƚ�
    if (root == NULL)
        return true;
    int left = MaxDepth(root->left);
    int right = MaxDepth(root->right);
    //ƽ���������ÿһ���ڵ����ȶ����ܳ���1����ֻ�Ǹ��ڵ������������Ȳ�����1
    //������Ҫ����ļ����ݹ�
    return (abs(left - right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}