#include<stdio.h>
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
 
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    //�ҵ�Ҷ�ӽڵ�Ȼ��ʼ����
    struct TreeNode* left = (invertTree(root->left));
    struct TreeNode* right = (invertTree(root->right));
    root->right = left;
    root->left = right;
    return root;
}