#include<bits/stdc++.h>

//最长回文子串的值
//回文子串模板


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_length = 0;
        string res = "";//返回值
        vector<vector<int>> dp(n,vector<int>(n,0));//二维dp数组，dp[i][j]表示i到j是否为回文串。
        if(n <= 1) return s;
        for(int j = 0 ; j < n ; j++ ){
            for(int i = 0 ; i <= j && i < n ; i++){
                if(j - i <= 1 && s[i] == s[j]) {
                    dp[i][j] = 1;
                    if(j-i+1 > max_length) max_length =j - i +1, res = s.substr(i , j - i + 1); //模板中增加这一行，更新结果字符串。
                }
                else if(dp[i+1][j-1] == 1 && s[i] == s[j]) {
                    dp[i][j] = 1;
                    if(j-i+1 > max_length) max_length =j - i +1, res = s.substr(i , j - i + 1);
                }
            }
        }
        return res;
    }
};


