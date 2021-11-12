#include<stdio.h>
#include<stdbool.h>

typedef struct TreeNode
{
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
}TreeNode;

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
int main()
{
    TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
    n1->val = 3;
    n2->val = 9;
    n3->val = 20;
    n4->val = 15;
    n5->val = 7;
    n1->left = n2;
    n1->right = n3;
    n2->left = NULL;
    n2->right = NULL;
    n3->left = n4;
    n3->right = n5;
    n4->left = NULL;
    n4->right = NULL;
    n5->left = NULL;
    n5->right = NULL;
    printf("%d ",maxDepth(n1));
}