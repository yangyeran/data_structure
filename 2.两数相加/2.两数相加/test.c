#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
typedef int LTDateType;
//动态申请节点
struct ListNode* BuyListNode(LTDateType x)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}
//给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
void _addTwoNumbers(struct ListNode* temp, struct ListNode* l1, struct ListNode* l2)
{
    //用循环来写
    int carry = 0;
    while (l1 != NULL && l2 != NULL)
    {
        int tmp = l1->val + l2->val + carry;
        //carry是进位
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
    //先遍历一遍，然后开辟一块空间相当于结构体数组
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
    //加一是为了防止最高位相加之后超过10，向上进一位
    struct ListNode* temp = BuyListNode(0);
    struct ListNode* temp1 = temp;
    while (--count1)
    {
        temp1->next = BuyListNode(0);
        temp1 = temp1->next;
    }
    temp1->next = NULL;
    //将开辟的空间链接起来
    int i = 0;
    _addTwoNumbers(temp, l1, l2);
    return temp;
}



//官方给的解法
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