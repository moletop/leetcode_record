#include<bits/stdc++.h>
using namespace std;


/*
解题思路：
经典问题：删除有序数组种的重复项。实现空间复杂度O(1)
经典双指针
K=2
*/



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return len;
        int i; int j;
        for(i = 2, j = 2; i <= j, j < len; j++){
            if(nums[j] != nums[i - 2]) nums[i++] = nums[j];
        }
        return i;
    }
};

