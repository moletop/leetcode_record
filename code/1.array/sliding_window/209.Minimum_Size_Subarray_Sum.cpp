#include<bits/stdc++.h>
using namespace std;
//经典滑动窗口:连续k个数的目标和以及改变的一些题目（数组中所有数都是正数）

class Solution{
public:
    int minSubArrayLen(int target,vector<int>& nums){
        int res = INT_MAX;
        int sum = 0;

        for (int l = 0, r = 0; l <=r && r <nums.size();) {
            sum += nums[r];
            while(sum >= target){
                res = min( res, r-l+1 );
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return res==INT_MAX ? 0:res;
    }
};

