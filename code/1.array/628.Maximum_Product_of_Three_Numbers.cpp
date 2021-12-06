#include<bits/stdc++.h>
using namespace std;
/*
排好序
        全是正数或者负数：三个最大值相乘
        有负数时：两位最小的乘一个最大的

        两者取最大

*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        return max(nums[0]*nums[1]*nums[2],nums[0]* nums[nums.size()-1]*nums[nums.size()-2]);

    }
};



