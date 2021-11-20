#include<bits/stdc++.h>
using namespace std;

class LRUCache {

public:
//双向链表加哈希表
    struct dNode{
        int key;
        int val;
        dNode* left;
        dNode* right;
        dNode(int _key, int _val):key(_key), val(_val),left(NULL),right(NULL){};
    }*L,*R;

    int cap;
    unordered_map<int,dNode*> map;//哈希表map存key的对应dnode节点地址

    void insert(dNode* p){//指针意义上的插入（指针操作）
        p -> left=L;
        p -> right = L -> right;
        L -> right = p;
        L -> right ->left = p;
    }
    void remove(dNode* p){//指针意义上的移除（指针操作）
        p -> left -> right = p -> right;
        p -> right -> left = p ->left;
    }

    LRUCache(int capacity) {//初始化，建立左右两边两个哨兵节点
        cap = capacity;
        L = new dNode(-1, -1);
        R = new dNode(-1, -1);
        L -> right = R;
        R -> left = L;


    }

    int get(int key) {//获取对应key的value, 注意：获取之后要将节点插入到链表的最前面！
        if(!map.count(key)) return -1;
        dNode* p = map[key];
        remove(p);
        insert(p);
        return p -> val;
    }

    void put(int key, int value) {
        if(map.count(key)){
            map[key] -> val = value;
            remove(map[key]);
            insert(map[key]);
        }
        else{
            if(map.size() == cap){
                dNode* p = R -> left;
                remove(p);
                map.erase(p->key);
                delete(p);//要回收，因为是前面put时建立的节点

            }
            auto node  = new dNode(key, value);
            map.insert(pair<int,dNode*>(key,node));
            insert(node);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */