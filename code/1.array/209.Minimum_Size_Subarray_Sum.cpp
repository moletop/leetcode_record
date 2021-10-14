#include<bits/stdc++.h>
using namespace std;
//经典滑动窗口
class Solution{
public:
    int minSubArrayLen(int target,vector<int>& nums){
        int res = INT_MAX;
        int sum = 0;
        int i = 0;//窗口前端
        for (int j = 0; j <nums.size() ; ++j) {//窗口后端
            sum += nums[j];
            while(sum>=target){
                res=min(res,j-i+1);//记录窗口宽度
                sum -= nums[i++];//窗口前端移动
            }
        }
        return res==INT_MAX ? 0:res;//返回逻辑
    }
};

