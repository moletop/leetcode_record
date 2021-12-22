#inlcude<bits/std++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *head1 = head;
        ListNode *head2 = split(head);

        head1 = sortList(head1);        //一条链表分成两段分别递归排序
        head2 = sortList(head2);

        return merge(head1, head2);     //返回合并后结果
    }


    //双指针找单链表中点模板
    ListNode *split(ListNode *head) {
        ListNode *slow = head, *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;           //断尾

        return mid;
    }


    //合并两个排序链表模板
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;

        while (head1 != nullptr && head2 != nullptr) {
            ListNode *pp = (head1->val < head2->val) ? head1 : head2;
            cur->next = pp;
            cur = cur->next;
            if (pp == head1) head1 = head1->next;
            else head2 = head2->next;
        }
        cur->next = (head1 == NULL) ? head2 : head1;
        return dummy->next;
    }
};


