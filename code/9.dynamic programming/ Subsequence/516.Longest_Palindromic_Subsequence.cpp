#include<bits/stdc++.h>
//注意回文子序列和回文子串的区别 ，回文子串是连续的，回文子序列是可以不连续的。
//对比:
//最长回文子串：因为子串是连续的，可以用j-i+1来计算长度，dp[i][j]表示：s[i]到是s[j]是否为回文子串。
//最长回文子序列：dp[i][j]表示： s[i]和s[j]之间的最长回文子序列的长度。

/*
//最长回文子串的长度值
class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        int res = 1;
        if(n == 1) return res;
        for(int j = 0; j < n; j ++){
            for(int i =0 ; i <= j && i < n; i ++){
                if(j - i <= 1 && A[i] == A[j]) dp[i][j] = 1; res = max(res , j-i+1);
                else if(dp[i+1][j-1] == 1 && A[i] == A[j]) dp[i][j] = 1, res = max(res , j-i+1);//模板小改，加个记录j-i+1的值就可以。
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n,0));
        for(int i = 0 ; i < n ; i++ ) dp[i][i] = 1;//初始化，对角线上的值

        for(int j = 1 ; j < n ; j++){
            for(int i = j - 1 ; i >= 0; i--){//注意递推顺序
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;//s[i] == s[j]
                else dp[i][j] = max(dp[i + 1][j] , dp[i][j - 1]);//s[i] != s[j]
            }
        }
        return dp[0][n-1];
    }
};

