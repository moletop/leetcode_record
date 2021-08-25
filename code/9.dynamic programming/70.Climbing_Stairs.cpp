#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> v(n+1);
        v[0]=0;
        v[1]=1;
        v[2]=2;
        for (int i =3 ; i < n+1; ++i) {
            v[i]=v[i-1]+v[i-2];
        }
        return v[n];
    }

        int climbStairs2(int n) {//优化版本
            if (n <= 1) return n;
            int dp[3];
            dp[1] = 1;
            dp[2] = 2;
            for (int i = 3; i <= n; i++) {
                int sum = dp[1] + dp[2];//只维持2个额外空间
                dp[1] = dp[2];
                dp[2] = sum;
            }
            return dp[2];
        }


