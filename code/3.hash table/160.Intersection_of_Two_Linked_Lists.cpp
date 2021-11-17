#include<bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        ListNode* cur = headA;
        while(cur != NULL){
            set.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        for(;cur != NULL;){
            if(set.count(cur)) return cur;
            cur = cur->next;
        }
        return NULL;

    }
};