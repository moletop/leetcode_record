#include<bits/stdc++.h>
using namespace std;
/*
1、dp[i][0]: 第i天手上没股票的最大收益
        dp[i][1]:第i天手上有股票的最大收益

2、状态方程：
dp[i][0] = max(dp[i - 1][0] , dp[i - 1 ][1] + prices[i]);前一天手上没股票 和 前一天手上有股票今天卖掉 ，其中挑最大值
dp[i][1] = max(dp[i - 1][0] - prices[i] , dp[i-1][1]);前一天手上没股票今天买入 和 前一天手上有股票 其中挑最大值

3.初始化：
 dp[0][0] = 0; dp[0][1] = - prices[0];

4.递推方向：从上到下，每一行只和上一行有关
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;

        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0] = 0; dp[0][1] = - prices[0];
        for(int i = 1 ; i < n ; i++){
            dp[i][0] = max(dp[i - 1][0] , dp[i - 1 ][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][0] - prices[i] , dp[i-1][1]);
        }
        return  dp[n-1][0]; //最后一天手上没股票的最大值
    }
};
/*还可以用贪心:

任何一个跨度的时间买卖可以分解成相邻两天的差值的累加。
假如第0天买入，第3天卖出，那么利润为：prices[3] - prices[0]。

相当于(prices[3] - prices[2]) + (prices[2] - prices[1]) + (prices[1] - prices[0])。

此时就是把利润分解为每天为单位的维度，而不是从0天到第3天整体去考虑！

差值只有三种情况： 负值，0 ，正值
        所以把所有正值加起来就是最优值。
*/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        int tem=0;
        for (int i = 0; i <prices.size()-1 ; ++i) {
            tem=prices[i+1]-prices[i];
            if(tem>0)
                result+=tem;
        }
        return result;
    }
};
*/

