#include<stdio.h>
#include<stdlib.h>
//������ѵ��ǿ����Ľڵ��randomû���κε���ϵ����������Ҫ������ϵ
//�����������������ӵ�ԭ����ĺ���ͱ���ԭ�ڵ���7 13 11 10 1   ����֮��7 7 13 13 11 11 10 10 1 1��������ͨ��ԭ������������random֮�����ϵ
//1.���ǽ������Ľڵ�������ԭ�ڵ����
//2.�ı俽���ڵ������random��ֵ��newNode->random=cur->random->next������ÿ���������random����������ϵ
//3.�Ͽ��ڵ㣬�������Ľڵ�������������ԭ����ָ�ԭ״��
  struct Node {
      int val;
      struct Node *next;
      struct Node *random;
  };
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    //���Ƚ������Ľڵ����ԭ�ڵ�ĺ���
    struct Node* cur = head;
    while (cur)//�������Ľڵ�������ÿ��ԭ�ڵ�ĺ���
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = cur->val;
        newNode->next = cur->next;
        cur->next = newNode;
        cur = cur->next->next;
    }
    //�ı�ڵ�����random��ֵ
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
    //�ߵ������Ѿ����Ӻ���
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