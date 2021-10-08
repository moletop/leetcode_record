#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {//1
                ret[stk.top()] = nums[i % n];//2
                stk.pop();
            }
            stk.push(i % n);//3
        }
        return ret;
    }
};

