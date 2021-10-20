#include<bits/stdc++.h>
using namespace std;
//贪心
class Solution {
public:
    int minOperations(vector<vector<int>>& grd, int x) {
        int n = grd.size();
        int m = grd[0].size();

        vector<int> cnt(m*n);//指定大小后空间更优
        int index = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                cnt[index++]=grd[i][j];
            }
        }//

        sort(cnt.begin(), cnt.end());
        int t = cnt.size()/ 2;//理论：所有数到中位数的距离之和最小

        int res = 0;
        for(int i = 0; i < cnt.size(); i ++){
            if(cnt[i] != cnt[t]){
                int k = abs(cnt[i] - cnt[t]);//计算差值，因为要化成相同的数，则所有数和中位数的差值都为x的整数倍才行
                if(k % x  == 0) res += k / x;
                else return -1;
            }
        }
        return res;
    }
};