#include<bit/stdc++.h>
using namespace std;

/*
dp[i][j] :以i，j为右下角的正方形的边长.
递推公式：dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]),dp[i-1][j-1]) + 1;
初始化：边界初始化if(matrix[i][j] =='1')
if(i == 0 || j == 0) dp[i][j] = 1;
递推方向:从上到下，从左到右能够满足递推需求
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res= 0;
        if(matrix.size() == 0) return 0;
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(),0));

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] =='1'){
                    if(i == 0 || j == 0) dp[i][j] = 1;
                    else{
                        dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]),dp[i-1][j-1]) + 1;
                    }
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};


