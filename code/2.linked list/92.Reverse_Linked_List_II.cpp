#include<bit/stdc++.h>
using namespace std;
/*
头插法经典案例

三个指针：pre,cur,next
pre:全程不动，指向要反转片段的前一个节点
cur:全程指向要反转链表的最开始的那个节点（指针没有移动过）
next：一直指向cur的下一个节点

        头插法流程：
cur -> next = next -> next;//cur所在节点跳过next,指向next的下一个节点
next -> next = pre ->next;//next所在节点指向pre的下一个节点
pre -> next = next; //pre所在节点指向next

next = cur -> next;//next指向cur的下一个节点
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * dumpy =new ListNode(-1);
        dumpy -> next = head;
        ListNode * pre = dumpy;

        for(int i = 0 ; i <left - 1; i++){
            pre = pre -> next;
        }

        ListNode* cur = pre -> next;
        ListNode* next = cur -> next;

        for(int i = left; i < right; i++){
            cur -> next = next -> next;
            next -> next = pre ->next;
            pre -> next = next;
            next = cur -> next;
        }
        return dumpy -> next;
    }
};

