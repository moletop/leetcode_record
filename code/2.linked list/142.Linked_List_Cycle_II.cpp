#include<bits/stdc++.h>
using namespace std;

//快慢指针，如果有环，一定会在环内相遇。在相遇处设index1，在头部设index2，相同速度前进，将在入口处相遇。
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {//防止fast->next->next跳两步，发生空指针错误
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
