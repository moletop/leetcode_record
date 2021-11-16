#include<bits/stdc++.h>
using namespace std;

/*
遍历两遍链表

第一遍建立老节点和新节点的无序map（因为）

第二遍建立对应的next和random指针
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;//无序map 底层哈希表实现
        Node* cur = head;
        while(cur != NULL){
            map[cur] = new Node(cur -> val);
            cur = cur -> next;
        }
        cur = head;
        while(cur != NULL){
            map[cur] -> next = map[cur -> next];
            map[cur] -> random = map[cur -> random];
            cur = cur ->next;
        }
        return map[head];
    }
};

