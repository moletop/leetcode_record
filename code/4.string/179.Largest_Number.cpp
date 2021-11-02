#include<bits/stdc++.h>
using namespace std;
//题目很明确：输出结果可能非常大，所以需要返回一个字符串而不是整数，一般这种题优先考虑直接字符串排序。

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        int n = nums.size();
        if(n == 1) return to_string(nums[0]);

        vector<string> s;
        for(int i = 0; i < n; i++){
            s.push_back(to_string(nums[i]));//转成字符串
        }
        sort(s.begin(), s.end(), [](string s1 , string s2){ return s1 + s2 > s2 +s1;});//字符串排序

        if(s[0] == "0") return "0";//如果开头就是零，直接输出零
        for(int i = 0; i < n; i++){
            res += (s[i]);
        }
        return res;
    }
};

