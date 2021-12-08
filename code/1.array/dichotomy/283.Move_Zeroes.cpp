#include<bits/stdc++.h>
using namespace std;

//同方向双指针：每次nums[r]不等于0， 就和nums[l] 交换，l++

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int l = 0, r = 0; r < n; r++){//l与r之间是0，l左边是处理好的数据，r右边是没处理的数据
            if(nums[r]!=0){
                swap(nums[l],nums[r]);//优化：可以加一个if(nums[l] == 0) 再交换
                l++;
            }

        }
    }
};

