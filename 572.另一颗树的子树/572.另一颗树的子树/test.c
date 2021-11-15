#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
 //首先思考几个问题
 //1.如何判断包含，包含就是需要两棵树一模一样，也就是说root相同部分就不能再有子树
 //2.要怎么比，可以先比左子树再比右子树
 //3.每一个节点都需要跟subRoot来比较
 //即用root的每一个节点都与subroot的根比较一遍
bool isSametree(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        //两个都为空
        if (root1 == root2)
            return true;
        else//其中有一个不为空，就代表两个不相等
            return false;
    }
    //就是两个都不为空，就开始比较值
    if (root1->val != root2->val)
        return false;
    //走到这是两个都相等，递归走下去,左右子树都需要相等
    return isSametree(root1->left, root2->left) && isSametree(root1->right, root2->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
        return false;
    //如果为true才会进入
    if (isSametree(root, subRoot))
    {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}