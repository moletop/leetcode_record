#include<bits/stdc++.h>

using namespace std;

/*
总结： 考察 虚拟头节点的使用，链表的遍历，元素定位和元素的删除。
*/



struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        //计算节点数
        ListNode *count = head;
        int num = 0;
        for (; count != NULL;) {
            num++;
            count = count->next;
        }

        //设置一个虚拟节点
        ListNode *vir = new ListNode();//注意必须new，不然next没有空间可以用
        vir->next = head;

        //定位到删除节点前一个节点
        ListNode *cur = vir;
        for (int i = 0; i < num - n; i++) {
            cur = cur->next;
        }

        //定位要删除的节点，后面好delete
        ListNode *del = cur->next;

        //删除(此步面试看情况写，一般只要删除new出来的节点)
        cur->next = cur->next->next; //注意：不需要判断删除的是否是最后一个节点。就算是最后一个节点，cur->next->next=NULL也成立。不会出现空指针异常
        delete del;


        //删除虚拟头节点，返回结果
        ListNode *res = vir->next;
        delete vir;
        return res;
    }
};




