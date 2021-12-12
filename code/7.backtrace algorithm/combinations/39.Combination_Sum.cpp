#include<bits/stdc++.h>
using namespace std;

/*
此题和 216.组合总和III 的区别就是可以重复选取

依旧使用回溯模板。

是单集合组合：所以要加start。
可以选取重复元素：所以递归每次从原位开始，表示可以重复选自己。

*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> & candidates, int target, int start){
        if(target <= 0){
            if(target  == 0) res.push_back(path);
            return ;
        }
        for(int i = start; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            target -= candidates[i];
            dfs(candidates, target, i);
            path.pop_back();
            target += candidates[i];
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        dfs(candidates, target, 0);

        return res;
    }
};

