#include<bits/stdc++.h>
using namespace std;

//dp[i][j]:长度为i+1,j结尾的字母序列个数，j的0，1，2，3，4对应a，e，i，o，u
class Solution {
public:
    int countVowelPermutation(int n) {
        const long long M = 1e9+7;//1e9+7小于2 的30次方，两个对它取模的数相加不会超过2的31次方（int）。相乘不会超过2的64次方（long long 19 位）
        vector<vector<long long>> dp(n,vector<long long>(5,1));
        for(int i = 1; i < n; i++){
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] +dp[i-1][4]) % M;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % M;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % M;
            dp[i][3] = dp[i-1][2] % M;
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % M;
        }
        return int((dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4]) % M);//1e9+7小于2的30次方。两个模过1e9+7的书相加不会超过2的31次方。但是这里是五个数。所以不一定，所以用long long存储，后面再转int
    }
};
/*优化
class Solution {
public:
    int countVowelPermutation(int n) {
        const long long M = 1e9+7;//1e9+7小于2 的30次方，两个对它取模的数相加不会超过2的31次方（int）。相乘不会超过2的64次放
        vector<long long> dp(5,1);
        vector<long long> tem(5,1);
        for(int i = 1; i < n; i++){
            tem[0] = (dp[1] + dp[2] +dp[4]) % M;
            tem[1] = (dp[0] + dp[2]) % M;
            tem[2] = (dp[1] + dp[3]) % M;
            tem[3] = dp[2] % M;
            tem[4] = (dp[2] + dp[3]) % M;
            dp = tem;
        }
        return int((dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % M);//1e9+7小于2的30次方。两个模过1e9+7的书相加不会超过2的31次方。但是这里是五个数。所以不一定，所以用long long存储，后面再转

    }
};

*/



/*
 * 大神简洁的代码
class Solution {
public:
    int countVowelPermutation(int n) {
        const int M = 1e9+7;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 2; k <= n; k++) {
            long aa = (e+i+u)%M;
            long ee = (a+i)%M;
            long ii = (e+o)%M;
            long oo = i;
            long uu = (o+i)%M;
            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
        }
        return (a+e+i+o+u)%M;
    }
};
*/