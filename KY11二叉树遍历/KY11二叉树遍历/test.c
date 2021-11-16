#include <stdio.h>
#include <malloc.h>
typedef struct BTNode
{
    char _data;
    struct BTNode* _left;
    struct BTNode* _right;
}BTNode;

//中序遍历
void Inorder(BTNode* root)
{
    if (root)
    {
        Inorder(root->_left);
        printf("%c ", root->_data);
        Inorder(root->_right);
    }
}

BTNode* CreatBTree(char* str, int* pi)
{
    if (str[*pi] != '#')
    {
        //当前节点非空，则创建当前节点
        BTNode* root = (BTNode*)malloc(sizeof(BTNode));
        root->_data = str[*pi];
        //字符位置向后移动一个位置
        ++(*pi);
        //创建左子树
        root->_left = CreatBTree(str, pi);
        //字符位置向后移动一个位置
        ++(*pi);
        //创建右子树
        root->_right = CreatBTree(str, pi);
        return root;
    }
    else
        return NULL;  //如果是空节点，则返回NULL
}

int main()
{
    char str[101];
    int i = 0;
    //读入字符串
    scanf("%s", str);
    //创建二叉树
    BTNode* root = CreatBTree(str, &i);
    //中序打印二叉树
    Inorder(root);
    printf("\n");
    return 0;
}