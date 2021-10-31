#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        ListNode* fast, * slow;
        fast = slow = A;
        while (fast && fast->next)
        {//找到中间节点
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* n1, * n2, * n3;
        n1 = slow;
        n2 = slow->next;
        n3 = slow->next->next;
        while (n2)
        {
            n1->next = NULL;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if (n3 != NULL)
            {
                n3 = n3->next;
            }
        }//逆置完成
        while (A && n1)
        {
            if (A->val != n1->val)
                return false;
            else
            {
                A = A->next;
                n1 = n1->next;
            }
        }
        return true;
    }
};