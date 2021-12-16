#include<bits/stdc++.h>
using namespace std;

//链表常用操作：虚节点，指针操作


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
 };



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            ListNode* pp = (l1->val < l2->val) ? l1 : l2;  //精辟写法，学习！
            cur->next = pp;
            cur = cur->next;
            if(pp == l1) l1= l1 ->next;
            else l2 = l2-> next;
        }
        cur->next = (l1 == nullptr) ? l2 : l1;//精辟写法，学习！

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

