#include<bits/stdc++.h>
using namespace std;
/*
dp[i][j]: text[0]到text1[i] 和 text[0]到text2[j]两个字符串的最小公共子序列

递推公式：

if(text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
else dp[i][j] = max(dp[i -1][j],dp[i][j -1]);

初始化和递推方向：由递推公式决定，分析发现，满足从左上角方向到右下角方向即可。
初始化这里要注意，先全部给1，然后把第一行和第一列初始化（防止数组越界），第一行第一列初始化整体规则为：一但出现相同的相同的字符，从这个字符到最后都是1，行列都是一样。
*/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        if(n1 == 0 || n2 == 0) return 0;
        vector<vector<int>> dp( n1 , vector<int>(n2 , 1));

        for(int j = 0; j < n2 && text1[0] != text2[j]; j++)  dp[0][j] = 0;
        for(int i = 0; i < n1 && text2[0] != text1[i]; i++) dp[i][0] = 0;//初始化判断条件很讲究：不相等给0，相等了就跳出

        for(int j = 1 ; j < n2 ; j++){
            for(int i = 1 ; i < n1 ; i++){
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else dp[i][j] = max(dp[i -1][j],dp[i][j -1]);
            }
        }
        return dp[n1 -1][n2 - 1];
    }
};


