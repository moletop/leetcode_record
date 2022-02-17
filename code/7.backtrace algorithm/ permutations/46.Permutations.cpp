#include<bits/stdc++.h>
using namespace std;

//和组合不同，因为排列问题，每次都要从头开始搜索，例如元素1在[1,2]中已经使用过了，但是在[2,1]中还要再使用一次1。也不需要start标记，
//但是需要一个tag数组来表示对应数字是否已经用过。

class Solution {
public:
    vector<vector<int>>res;//符合条件的结果结合
    vector<int> path;//单条符合条件的结果

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tag(nums.size(),0);
        dfs(nums , tag);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> tag){//回溯
        if(path.size() == nums.size())  res.push_back(path);//找到一条记录的条件：递归终止条件

        for(int i = 0; i < nums.size() ; i++){//中——左——回溯的结构
            if(tag[i] == 1) continue;
            else{
                tag[i] = 1;
                path.push_back(nums[i]);
                dfs(nums , tag);
                path.pop_back();
                tag[i] = 0;
            }
        }
    }
};

