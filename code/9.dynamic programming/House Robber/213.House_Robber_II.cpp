#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int robrange(vector<int>&nums,int l,int r){
        if(l-r==1) return max(nums[l],nums[r]);
        int dp1=nums[l];
        int dp2=max(nums[l],nums[l+1]);
        for(int i=l+2;i<=r;i++){
            int tem =max(dp2,dp1+nums[i]);
            dp1=dp2;
            dp2=tem;
        }
        return dp2;
    }


    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        return max(robrange(nums,0,nums.size()-2),robrange(nums,1,nums.size()-1));
    }
};