#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() == i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
}



int main() {
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    Solution solution;
    vector<int> result = solution.maxSlidingWindow(nums,k);
    for (int i = 0; i <result.size() ; ++i) {
        cout<< result[i];
    }


    return 0;
}