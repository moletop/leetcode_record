#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            mid -= mid & 1;
            if(nums[mid] != nums[mid + 1]) r = mid;
            else l = mid + 2;
        }
        return nums[r];
    }
};

int main(){
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    Solution s;
    int res = s.singleNonDuplicate(nums);
    cout << res << endl;
}
