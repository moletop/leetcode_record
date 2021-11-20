#include<bits/stdc++.h>

using namespace std;

/*
分析题目的操作过程，要让put和get方法的时间复杂度为0（1）
我们可以总结出cache这个数据结构必要的条件：查训快，插入快，删除快，有顺序要求。

cache必须有顺序之分，以区分最近使用的和久未使用的数塘；而且我们要在cache中查找键是否已存在；
如果容量满了要删除最后一个数据；每次访问过还要把数据插入到队头

什么数据结构同时符合上述条件呢？
哈希表查找快，但是数据无固定顺序；链表有顺序之分，插入删除快，但是查找慢。
所以结合一下，形成一种新的数据结构：哈希链表。
 LRU緩存算法的核心数据結构就是哈希链表，双向链表和哈希表的結合体。
 */


//单向链表不太好，因为remove节点时，要找倒数第二个节点（包括了哨兵节点），双向就能很快找到

//很经典。

#include<bits/stdc++.h>

using namespace std;

class LRUCache {

public:
//双向链表加哈希表
    struct dNode {
        int key;
        int val;
        dNode *left;
        dNode *right;

        dNode(int _key, int _val) : key(_key), val(_val), left(NULL), right(NULL) {}
    } *L, *R;

    int cap;
    unordered_map<int, dNode *> map;//哈希表map存key的对应dnode节点地址

    void insert(dNode *p) {//指针意义上的插入（指针操作）
        p->left = L;
        p->right = L->right;
        L->right->left = p;//！解指针原则，对于已知表示的节点，先把进来的指针先全部解除先
        L->right = p;

    }

    void remove(dNode *p) {//指针意义上的移除（指针操作）
        p->left->right = p->right;
        p->right->left = p->left;
    }

    LRUCache(int capacity) {//初始化，建立左右两边两个哨兵节点
        cap = capacity;
        L = new dNode(-1, -1);
        R = new dNode(-1, -1);
        L->right = R;
        R->left = L;


    }

    int get(int key) {//获取对应key的value, 注意：获取之后要将节点插入到链表的最前面！
        if (!map.count(key)) return -1;
        auto p = map[key];
        remove(p);
        insert(p);
        return p->val;
    }

    void put(int key, int value) {
        if (map.count(key)) {//如果已经存在，修改值，并且插入到链表最前面
            auto p = map[key];
            p->val = value;
            remove(p);
            insert(p);
        } else {//否则
            if (map.size() == cap) {//如果缓存区满了
                auto p = R->left;
                map.erase(p->key);//删掉map中的(key:节点地址）

                p->key = key;//重写节点上的key和value
                p->val = value;
                map[key] = p;//重写map
                remove(p);//更新指针
                insert(p);

            } else {//如果没满，建立新节点，然后更新map,更新指针
                auto node = new dNode(key, value);
                map[key] = node;
                insert(node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


