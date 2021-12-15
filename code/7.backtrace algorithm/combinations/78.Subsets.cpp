#include<bits/stdc++.h>
using namespace std;
/*
回溯模板，还是一个res,一个path。

计算子集时，每个元素只有两种状态：选或者不选

和494.目标和一样，只有取正或者取负。

*/

class Solution {
public:
    void dfs(vector<int> nums, vector<vector<int>>& res, vector<int> path, int cur){
        if(cur == nums.size()){
            res.push_back(path);
            return;
        }
        //选择
        path.push_back(nums[cur]);
        dfs(nums, res, path, cur + 1);
        //不选择
        path.pop_back();//回溯
        dfs(nums, res, path, cur + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, res, path, 0);
        return res;
    }
};
