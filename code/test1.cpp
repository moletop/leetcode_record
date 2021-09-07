#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {

        if(nums.size()<=1) return nums;
        //快慢指针
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            //左
            if(nums[left]%2!=0){left++;continue;}//每次continue直接进入while判断：表示每次指针移动都判断，以防越界
            //右
            if(nums[right]%2!=1){ right--;continue;}

            if(left<right) swap(nums[left++],nums[right--]);
        }
        return nums;

    }
};

int main(){
    Solution solution;
    vector<int> nums={1,2,3,4,5,6};
    vector<int> res=solution.exchange(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<" ";
    }

    return 0;
}

