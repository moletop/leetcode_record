#include<bits/stdc++.h>
using namespace std;

//我：时间复杂度:O(nlogn)
class Solution {
public:
    int count(int num){
        int res = 0;
        while(num != 0){
            if(num%2 == 1) res ++;
            num /= 2;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++){
            res.push_back(count(i));
        }
        return res;
    }
};


//大佬:动态规划   时间复杂度:O(n)
/*
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1);
        result[0] = 0;
        for(int i = 1; i <= num; i++)
        {
            if(i % 2 == 1)
            {
                result[i] = result[i-1] + 1;//奇数比前一个偶数多1
            }
            else
            {
                result[i] = result[i/2];// 偶数为前一偶数左移一位而来，2是由1左移一位而来
            }
        }
        return result;
    }
};
*/