#include<bits/stdc++.h>
using namespace std;

class LockingTree {
public:
    int locked[2005]={0};
    int dad[2005];
    vector<vector<int>> graph;

    LockingTree(vector<int>& parent) {
        graph.resize(parent.size());
        for(int i=0;i<parent.size();i++){
            if(parent[i]>=0)
                graph[parent[i]].push_back(i);
            dad[i]=parent[i];
        }
    }

    bool lock(int num, int user) {
        if(locked[num]==0){
            locked[num]=user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if(locked[num]==user){
            locked[num]=0;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if(locked[num]!=0)
            return false;
        if(locked_sons(num)==0)
            return false;
        if(locked_dad(num)>0)
            return false;

        locked[num]=user;
        upgrade(num);
        return true;
    }

    void upgrade(int u){
        for(auto&i:graph[u]){
            locked[i]=0;
            upgrade(i);
        }
    }

    int locked_sons(int u){
        int sum=0;
        for(auto&i:graph[u]){
            sum+=locked_sons(i);
        }
        if(locked[u]>0)sum++;
        return sum;
    }

    int locked_dad(int u){
        if(u==-1)return 0;
        return locked_dad(dad[u])+(locked[u]>0);
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */