#include<bits/stdc++.h>
using namespace std;

/*
典型的二分查找
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return vector<int>{-1,-1};

        int l = 0;
        int r = nums.size() - 1;

        for(;l <= r ;){
            int mid = l +(r - l)/2;//中点
            if(target > nums[mid]) l = mid + 1;
            else if(target < nums[mid]) r = mid - 1;
            else{
                int left = mid;
                int right = mid;
                while(left >=0 && nums[left] == target) left--;
                while(right < nums.size() && nums[right] == target) right++;
                return vector<int>{left + 1, right - 1};
            }
        }
        return vector<int>{-1,-1};
    }
};
