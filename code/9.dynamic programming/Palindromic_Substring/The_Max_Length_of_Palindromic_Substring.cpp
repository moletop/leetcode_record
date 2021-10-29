#include<bits/stdc++.h>
using namespace std;
//最长回文子串的长度值
class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        int res = 1;
        if(n == 1) return res;
        for(int j = 0; j < n; j ++){
            for(int i =0 ; i <= j && i < n; i ++){
                if(j - i <= 1 && A[i] == A[j]) dp[i][j] = 1;
                else if(dp[i+1][j-1] == 1 && A[i] == A[j]) dp[i][j] = 1, res = max(res , j-i+1);//小改，记录j-i+1的值就可以。
            }
        }
        return res;
        // write code here
    }
};