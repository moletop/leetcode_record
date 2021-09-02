#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for (int i = 1; i < n+1; ++i) {
            for (int j = 0; j <i ; ++j) {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

