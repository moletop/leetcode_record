#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {//暴力
public:
    int maxSubArray1(vector<int> &nums) {
        if (nums.size() == 0) return 0;

        int result = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int sum = nums[i];
            if (sum > result) result = sum;//本身的判断

            for (int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];//累加的判断
                if (sum > result) result = sum;
            }
        }
        return result;
    }

    int maxSubArray2(vector<int> &nums) {// 动态规划: 若前一个元素大于零，则将其加到下一个元素上
        for (int i = 0; i < nums.size()-1; ++i) {
            if(nums[i]>=0) nums[i+1]+=nums[i];

        }
        sort(nums.begin(),nums.end());
        return nums[nums.size()-1];
    }
};

int main (){
    vector<int> nums;
    int tem;
    Solution solution;
    while(cin>>tem){
        nums.push_back(tem);
        if(getchar()=='\n')
        break;
    }
    int result1=solution.maxSubArray1(nums);
    int result2=solution.maxSubArray2(nums);
    cout<<result1<<'\n'<<result2<<endl;
    return 0;
}