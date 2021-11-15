#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
 //����˼����������
 //1.����жϰ���������������Ҫ������һģһ����Ҳ����˵root��ͬ���־Ͳ�����������
 //2.Ҫ��ô�ȣ������ȱ��������ٱ�������
 //3.ÿһ���ڵ㶼��Ҫ��subRoot���Ƚ�
 //����root��ÿһ���ڵ㶼��subroot�ĸ��Ƚ�һ��
bool isSametree(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        //������Ϊ��
        if (root1 == root2)
            return true;
        else//������һ����Ϊ�գ��ʹ������������
            return false;
    }
    //������������Ϊ�գ��Ϳ�ʼ�Ƚ�ֵ
    if (root1->val != root2->val)
        return false;
    //�ߵ�������������ȣ��ݹ�����ȥ,������������Ҫ���
    return isSametree(root1->left, root2->left) && isSametree(root1->right, root2->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
        return false;
    //���Ϊtrue�Ż����
    if (isSametree(root, subRoot))
    {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}