#include<bits/stdc++.h>
using namespace std;
/*
int 范围：-2147483648 —— 2147483647
从倒数第二位开始判断是否会溢出
*/


class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            int tem = x % 10;
            x /= 10;
            if(res >INT_MAX / 10 || res == INT_MAX / 10 && tem > 7) return 0;//从倒数第二位开始判断是否会溢出
            if(res < INT_MIN / 10 || res == INT_MIN / 10 && tem < -8) return 0;
            res =10*res + tem;
        }
        return res;

    }
};

