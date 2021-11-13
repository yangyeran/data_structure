#include<stdio.h>
#include<stdlib.h>
//returnSize�������ϸ��ķ���ֵ�����ص��������ܴ�С
//Ҫ�󷵻����malloc���ٳ�����������Ԫ�ص�ַ
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
  //���������ж��ٸ��ڵ�
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
//ǰ��������ڵ���ڿ��ٵ�������
void _preorderTraversal(struct TreeNode* root, int* Treenode, int* pi)
{
    if (root == NULL)
        return;
    //Ҫ�������ȼ�
    Treenode[(*pi)++] = root->val;
    _preorderTraversal(root->left, Treenode, pi);
    _preorderTraversal(root->right, Treenode, pi);
}
//���庯��
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* Treenode = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _preorderTraversal(root, Treenode, &i);
    return Treenode;
}