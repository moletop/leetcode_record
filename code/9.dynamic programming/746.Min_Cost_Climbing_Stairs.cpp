#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size());
        dp[0]=cost[0];
        dp[1]=cost[1];
        int sum=dp[0]+dp[1];
        for (int i = 2; i <cost.size(); ++i) {
            int tem=min(dp[0],dp[1])+cost[i];
            dp[0]=dp[1];
            dp[1]=tem;
        }
        return min(dp[cost.size()-1],dp[cost.size()-2]);

    }
};
