#include<bits/stdc++.h>
using namespace std;

//迭代，一层一层网上移动.dfs和链表操作的结合考察，这里只是模拟过程，没有dfs



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        for(;cur != NULL; cur= cur->next){遍历
            if(cur -> child){
                //下层的元素[start，end]
                Node* start = cur -> child;
                Node* end = start;
                while(end->next)  end = end ->next;
                //指针变换，end和cur->next之间
                end -> next = cur-> next;
                if(cur->next) cur->next->prev = end;//注意cur->next为空的时候，prev不存在
                //指针变换，cur和start之间
                cur->next = start;
                start->prev= cur;
                cur->child = NULL;
            }
        }
        return head;
    }
};



