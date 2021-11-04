#include<bits/stdc++.h>
using namespace std;

//dp[i]:结尾为nums[i]的递增子序列中的最长递增子序列。
//核心代码：
//if(nums[i] < nums[j]) dp[j] = max( dp[j], dp[i] + 1);

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n <= 0) return n;
        int res = INT_MIN;
        vector<int> dp(n, 1);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j]) dp[j] = max(dp[j], dp[i] + 1);//确定j之后，从i=0遍历到i=j-1,不断计算更新i到j之间的最长递增子序列（d[j]）
                if (dp[j] > res) res = dp[j];
            }
            return res;
        }
    }
};