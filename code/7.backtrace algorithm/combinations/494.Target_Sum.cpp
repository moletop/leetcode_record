#include<bits/stdc++.h>
using namespace std;

//回溯法中的参数，要能提供树的初始宽度和递归深度信息，还有每一次递归的起点这个参数。这里每一层的宽度都是2（每个数的正负值），深度参数level表示树的宽度（遍历到哪个数了）


class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrace(nums, target, 0, 0);
        return count;
    }

    void backtrace(vector<int> &nums, int target, int level, int sum){
        if(level == nums.size()){
            if(sum == target) count++;
            return;
        }
        backtrace(nums, target, level+1 , sum + nums[level]);
        backtrace(nums, target, level+ 1, sum - nums[level]);
//上面这样写回溯不那么明显,下面这样就很清楚。但是时间复杂度会变高
/*
        sum += nums[level];
        backtrace(nums, target, level+1 , sum + nums[level]);
        sum -= nums[level]

        sum -= nums[level]
        backtrace(nums, target, level+ 1, sum - nums[level]);
*/
    }
};

