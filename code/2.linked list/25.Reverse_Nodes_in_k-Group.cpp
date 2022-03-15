#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int v) : val(v), next(NULL) {}
};

ListNode *crea_node(vector<int> nums) {
    if (nums.size() == 0) return NULL;
    ListNode *firnode = new ListNode(nums[0]);
    ListNode *cur = firnode;
    for (int i = 1; i < nums.size(); i++) {
        ListNode *node = new ListNode(nums[i]);
        cur->next = node;
        cur = node;
    }
    return firnode;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    int len = 0;
    ListNode *cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy;
    cur = head;
    ListNode *nex;
    for (int i = 0; i < len / k; i++) {
        for (int j = 0; j < k - 1; j++) {
            nex = cur->next;
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        pre = cur;
        cur = cur->next;
    }
    return dummy->next;
}


int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    ListNode *list = crea_node(vec);
    ListNode *res = reverseKGroup(list, 2);
    while (res) {
        cout << res->val;
        res = res->next;
    }
    return 0;
}

