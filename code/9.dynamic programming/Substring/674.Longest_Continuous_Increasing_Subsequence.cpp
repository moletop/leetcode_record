#include<bits/stdc++.h>
using namespace std;
/*
dp[i]:以nums[i] 结尾的最大连续递增序列（连续子串）

递推公式 :
if(nums[i] > nums[i -1]) dp[i] = dp[i -1] + 1;

else dp[i] = 1;

初始化: d[0] = 1

递推方向： 从左到右
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 0);

        dp[0] =1;
        for(int i =1 ; i < n ; i++){
            if(nums[i] > nums[i -1]) dp[i] = dp[i -1] + 1;
            else dp[i] = 1;
        }
        return *max_element(dp.begin(),dp.end());
    }
};
