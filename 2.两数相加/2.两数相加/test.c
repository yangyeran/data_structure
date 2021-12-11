#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
typedef int LTDateType;
//��̬����ڵ�
struct ListNode* BuyListNode(LTDateType x)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}
//���������ǿյ�������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ�������ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢һλ���֡�
void _addTwoNumbers(struct ListNode* temp, struct ListNode* l1, struct ListNode* l2)
{
    //��ѭ����д
    int carry = 0;
    while (l1 != NULL && l2 != NULL)
    {
        int tmp = l1->val + l2->val + carry;
        //carry�ǽ�λ
        if (tmp < 10)
        {
            carry = 0;
            temp->val = tmp;
            if (temp->next != NULL)
                temp = temp->next;
        }
        else//tmp>=10
        {
            tmp %= 10;
            carry = 1;
            temp->val = tmp;
            if (temp->next != NULL)
                temp = temp->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        int tmp = l1->val + carry;
        if (tmp < 10)
        {
            carry = 0;
            temp->val = tmp;
            if (temp->next != NULL)
                temp = temp->next;
        }
        else//tmp>=10
        {
            tmp %= 10;
            carry = 1;
            temp->val = tmp;
            if (temp->next != NULL)
                temp = temp->next;
        }
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        int tmp = l2->val + carry;
        if (tmp < 10)
        {
            carry = 0;
            temp->val = tmp;
            if (temp->next != NULL)
                temp = temp->next;
        }
        else//tmp>=10
        {
            tmp -= 10;
            carry = 1;
            temp->val = tmp;
            if (temp->next != NULL)
                temp = temp->next;
        }
        l2 = l2->next;
    }
    if (carry == 1)
    {
        temp->next = BuyListNode(carry);
    }
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //�ȱ���һ�飬Ȼ�󿪱�һ��ռ��൱�ڽṹ������
    int count1 = 0, count2 = 0;
    struct ListNode* cl1 = l1;
    struct ListNode* cl2 = l2;
    while (cl1 != NULL)
    {
        ++count1;
        cl1 = cl1->next;
    }
    while (cl2 != NULL)
    {
        ++count2;
        cl2 = cl2->next;
    }
    if (count1 < count2)
        count1 = count2;
    //��һ��Ϊ�˷�ֹ���λ���֮�󳬹�10�����Ͻ�һλ
    struct ListNode* temp = BuyListNode(0);
    struct ListNode* temp1 = temp;
    while (--count1)
    {
        temp1->next = BuyListNode(0);
        temp1 = temp1->next;
    }
    temp1->next = NULL;
    //�����ٵĿռ���������
    int i = 0;
    _addTwoNumbers(temp, l1, l2);
    return temp;
}



//�ٷ����Ľⷨ
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//    struct ListNode* head = NULL, * tail = NULL;
//    int carry = 0;
//    while (l1 || l2) {
//        int n1 = l1 ? l1->val : 0;
//        int n2 = l2 ? l2->val : 0;
//        int sum = n1 + n2 + carry;
//        if (!head) {
//            head = tail = malloc(sizeof(struct ListNode));
//            tail->val = sum % 10;
//            tail->next = NULL;
//        }
//        else {
//            tail->next = malloc(sizeof(struct ListNode));
//            tail->next->val = sum % 10;
//            tail = tail->next;
//            tail->next = NULL;
//        }
//        carry = sum / 10;
//        if (l1) {
//            l1 = l1->next;
//        }
//        if (l2) {
//            l2 = l2->next;
//        }
//    }
//    if (carry > 0) {
//        tail->next = malloc(sizeof(struct ListNode));
//        tail->next->val = carry;
//        tail->next->next = NULL;
//    }
//    return head;
//}

int main()
{
    struct ListNode* s1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s7 = (struct ListNode*)malloc(sizeof(struct ListNode));
    s1->val = 9;
    s2->val = 9;
    s3->val = 9;
    s4->val = 9;
    s5->val = 9;
    s6->val = 9;
    s7->val = 9;
    s1->next = s2;
    s2->next = s3;
    s3->next = s4;
    s4->next = s5;
    s5->next = s6;
    s6->next = s7;
    s7->next = NULL;
    struct ListNode* s11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s22 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s33 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s44 = (struct ListNode*)malloc(sizeof(struct ListNode));
    s11->val = 9;
    s22->val = 9;
    s33->val = 9;
    s44->val = 9;
    s11->next = s22;
    s22->next = s33;
    s33->next = s44;
    s44->next = NULL;
    struct ListNode* temp=addTwoNumbers(s1,s11);
    for (int i = 0; i < 8; ++i)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}