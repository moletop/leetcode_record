#include<bits/stdc++.h>
using namespace std;
//一次买卖的股票

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> dp (n, 0);//dp[i]: 第i天能获得的最大收益
        int minprice = prices[0];

        for (int i = 1; i < n; i++){
            minprice = min(minprice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minprice);//递推公式：prices[i] - minprice：当天的价格减去历史最低价格
        }
        return dp[n - 1];
    }
};



/*本质有点贪心的味道。可以不用dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int res = 0;  int tem_min = prices[0];
        for(int i = 1; i < n ; i++){
            tem_min = min(tem_min, prices[i]);
            res= max(res ,prices[i] - tem_min);
        }
        return res;
    }
};
*/


