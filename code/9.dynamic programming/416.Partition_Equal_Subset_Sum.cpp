#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(10001,0);

        int sum=0;
        for (int i = 0; i < nums.size(); ++i) {
            sum+=nums[i];
        }
        if(sum&1) return false;


        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum/2; j >=nums[i] ; --j) {
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }

        if(dp[sum/2]==sum/2) return true;

        return false;

    }
};

