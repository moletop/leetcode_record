include<bit/stdc++.h>
using namespace std;

/*
经典链表判圈算法！
可以衍生很多题目。
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fir = head;
        ListNode* sec = head;
        while(sec != NULL){
            if(sec-> next == NULL) return false;
            sec = sec ->next ->next;
            fir = fir -> next;
            if(fir == sec) return true;
        }
        return false;

    }
};

