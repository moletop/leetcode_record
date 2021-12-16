#include<bits/stdc++.h>
using namespace std;

/*
经典链表判圈算法！
可以衍生很多题目。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fir = head;
        ListNode *sec = head;
        while (sec != nullptr) {
            if (sec->next ==nullptr) return false;
            sec = sec->next->next;
            fir = fir->next;
            if (fir == sec) return true;
        }
        return false;
    }
};

int main(){
    //初始化
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for(int i = 0; i < 5; i++){
        ListNode * node = new ListNode(i);
        cur -> next = node;
        cur = cur -> next;
    }
    //cur -> next = head;

    //测试
    Solution s;
    bool res = s.hasCycle(head);
    printf("%d",res);
}

