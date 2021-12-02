#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 0;
        sort(nums.begin(),nums.end());int res=INT_MAX;
        for (int i = 0; i <=nums.size()-k; ++i) {
            if((nums[i+k-1]-nums[i])<res) res=nums[i+k-1]-nums[i];
        }
        return res;
    }
};