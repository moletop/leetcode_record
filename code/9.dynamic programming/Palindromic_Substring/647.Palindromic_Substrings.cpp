#include<bits/stdc++.h>
using namespace std;
//回文子串的数目（作为模板拓展）
//递推公式：dp[i][j]= dp[i+1][j-1]。

class Solution {
public:
    int countSubstrings(string s) {
        //dp[i][j] :i 到 j是否为回文子串
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int res = 0;

        for(int j = 0; j < s.size(); j++){
            for(int i =0 ; i <= j && i < s.size(); i++){
                if(j - i <= 1 && s[i] == s[j]) dp[i][j] = 1,res++;//比如单独的a和aa
                else if (dp[i+1][j-1]==1 && s[i]==s[j]) dp [i][j] =1,res++;//长度超过2  就利用递推。
            }
        }
        return res;
    }
};
