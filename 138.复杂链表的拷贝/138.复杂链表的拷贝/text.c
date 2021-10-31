#include<stdio.h>
#include<stdlib.h>
//这题的难点是拷贝的节点的random没有任何的联系，所以我们要建立联系
//即将拷贝的链表连接到原链表的后面就比如原节点是7 13 11 10 1   链接之后7 7 13 13 11 11 10 10 1 1这样就能通过原链表来建立起random之间的联系
//1.就是将拷贝的节点链接在原节点后面
//2.改变拷贝节点里面的random的值（newNode->random=cur->random->next）这就让拷贝的两个random建立起了联系
//3.断开节点，将拷贝的节点链接起来，将原链表恢复原状。
  struct Node {
      int val;
      struct Node *next;
      struct Node *random;
  };
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    //首先将拷贝的节点接在原节点的后面
    struct Node* cur = head;
    while (cur)//将拷贝的节点链接在每个原节点的后面
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = cur->val;
        newNode->next = cur->next;
        cur->next = newNode;
        cur = cur->next->next;
    }
    //改变节点里面random的值
    cur = head;
    while (cur)
    {
        struct Node* newNode = cur->next;
        if (cur->random == NULL)
            newNode->random = NULL;
        else
            newNode->random = cur->random->next;
        cur = newNode->next;
    }
    //走到这里已经链接好了
    struct Node* pHead, * tail;
    pHead = tail = (struct Node*)malloc(sizeof(struct Node));
    cur = head;
    while (cur)
    {
        tail->next = cur->next;
        tail = tail->next;
        if (cur->next)
            cur->next = cur->next->next;
        cur = cur->next;
    }
    return pHead->next;
}
int main()
{
    struct Node* s1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s5 = (struct Node*)malloc(sizeof(struct Node));
    s1->val = 7;
    s2->val = 13;
    s3->val = 11;
    s4->val = 10;
    s5->val = 1;
    s1->next = s2;
    s2->next = s3;
    s3->next = s4;
    s4->next = s5;
    s5->next = NULL;
    s1->random = NULL;
    s2->random = s1;
    s3->random = s5;
    s4->random = s3;
    s5->random = s1;
    copyRandomList(s1);
}