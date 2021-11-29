#include<bits/stdc++.h>
using namesapce std;
/*
一个数和 0 做 XOR 运算等于本身：a⊕0 = a
一个数和其本身做 XOR 运算等于 0：a⊕a = 0
XOR 运算满足交换律和结合律：a⊕b⊕a = (a⊕a)⊕b = 0⊕b = b

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res= 0;
        for(auto i :nums)
            res ^= i;
        return res;

    }
};

