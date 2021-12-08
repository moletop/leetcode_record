
#include<bits/stdc++.h>
using namespace std;

//三数之和 典型的双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            //if(nums[i] > 0  || n < 3) return res;//加上可以优化
            if(i > 0 && nums[i] == nums[i - 1])  continue;//第一个元素的去重

            int l = i + 1; //第二个元素位置
            int r = nums.size() - 1;//第三个元素位置

            while(l < r){
                if(nums[i] + nums[l] + nums[r] < 0) l++;
                else if(nums[i] + nums[l] + nums[r] >0 ) r--;
                else{ res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while( l < r && nums[l] ==nums[l + 1]) l++;//第二个元素去重
                    while( l < r && nums[r] == nums[r - 1]) r--;//第三个元素去重
                    l++;//继续滑动l，r指针
                    r--;
                }
            }
        }
        return res;
    }
};