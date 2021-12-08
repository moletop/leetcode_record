#include<bits/stdc++.h>
using namespace std;

//我的解答：
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int tem = 0;
        while(l1 != NULL && l2 != NULL){//处理公共长度
            int sum = l1 -> val + l2 -> val + tem;
            if(sum >= 10){sum -= 10, tem = 1;}
            else tem = 0;
            ListNode* node = new ListNode(sum);
            cur -> next = node; cur = cur ->next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if(!l1 && !l2){//处理完之后看是否都为空
            if(tem == 0) return dummy -> next;
            else{
                ListNode* node = new ListNode(tem);
                cur -> next = node;
            }
        }
        else{//如果不是都为空
            ListNode * rest = (l1 == NULL ? l2 : l1);
            while(rest){
                int sum = rest -> val + tem;
                if(sum >= 10) {sum -= 10; tem = 1;}
                else tem = 0;
                ListNode * node = new ListNode(sum);
                cur -> next = node; cur = cur -> next;
                rest = rest ->next;
            }
        }

        if(tem == 0) return dummy -> next;//全部处理完之后，最后的进位处理。
        else{
            ListNode* node = new ListNode(tem);
            cur -> next = node;
        }
        return dummy -> next;
    }
};

//大佬的解答:
/*

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode *l2) {
        ListNode* pre = new ListNode(0);
        ListNode* cur = pre;
        int carry = 0;
        while(l1 || l2) {//有一条链没结束就继续
            int x = l1 == NULL ? 0 : l1 -> val;//有数就取数，没数就补零，很机智！
            int y = l2 == NULL ? 0 : l2 -> val;
            int sum = x + y + carry;

            carry = sum / 10;
            sum = sum % 10;
            cur -> next = new ListNode(sum);//匿名节点

            cur = cur -> next;
            if(l1)
                l1 = l1 -> next;
            if(l2)
                l2 = l2 -> next;
        }
        if(carry == 1) {//最后的进位检查
            cur->next = new ListNode(carry);
        }
        return pre -> next;
    }
};

 *
*/