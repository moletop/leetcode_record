#include<bits/stdc++.h>
using namespace std;
//回溯法的搜索过程就是一个树型结构的遍历过程，在如上图中，for循环用来横向遍历，递归的过程是纵向遍历。



class Solution {
private:
    vector<int> path;// 存放符合条件结果的集合
    vector<vector<int>>res;//单个符合条件的结果
    void backtracking(int n , int k , int start){//start表示每下一个节点从哪里开始
        if(path.size() == k){//返回条件
            res.push_back(path);
            return;
        }
        for(int i = start ; i <=n ; i++){
            path.push_back(i);//处理当前节点
            backtracking(n , k , i + 1);//向下递归
            path.pop_back();// 回溯，撤销处理的节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking (n , k , 1);
        return res;
    }
};

