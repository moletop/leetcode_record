#include<bit/stdc++.h>
using namespace std;
//思路参考：https://leetcode-cn.com/problems/number-of-ways-to-paint-n-3-grid/solution/shu-xue-jie-jue-fei-chang-kuai-le-by-lindsaywong/


class Solution {
public:
    int numOfWays(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 12;
        long temp = 1000000007;
        long  p = 6;
        long  q = 6;
        for(int i = 2; i <=n; i++)
        {
            long  new_p = p * 3 % temp + q * 2 % temp;
            long  new_q = p * 2 % temp + q * 2 % temp;
            p = new_p;
            q = new_q;
        }
        return (int)((p + q)%temp);
    }
};

