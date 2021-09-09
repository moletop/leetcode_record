#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

//经典双端队列

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while(!q.empty()&&nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);//队列中存储的是下标
        }

        vector<int> result={nums[q.front()]};
        for (int i = k; i <nums.size() ; ++i) {//窗口移动
            while(!q.empty()&&nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);

            while(q.front()==i-k){//如果最大值是窗口前面的值，则弹出
                q.pop_front();
            }
            result.push_back(nums[q.front()]);//每次移动，都获取以一个最大值
        }
        return result;
    }
};



int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    Solution solution;
    vector<int> result = solution.maxSlidingWindow(nums,k);
    for (int i = 0; i <result.size() ; ++i) {
        cout<< result[i];
    }

}