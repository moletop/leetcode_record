#include<bits/stdc++.h>
using namespace std;
/*

与209题区分。此题注意，不能用滑动窗口。因为nums中有负数，滑动窗口适合全是正数的，这样右窗口右话和就会变大，左窗口左滑和就会变小。

正负都有时，求数组连续目标和，用前缀和技巧

此题还用了哈希表，很经典。
*/




class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> map;
        map[0] = 1;//注意这一步初始化。开始之前，一个数都没有时，前缀和为0，占了一个次数，后面有前缀和为k时就能计算上了，不会漏次数。

        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];//计算当下位置前缀和
            if(map.find(sum - k) != map.end()) res+= map[sum -k];
            map[sum]++;
        }
        return res;
    }
};