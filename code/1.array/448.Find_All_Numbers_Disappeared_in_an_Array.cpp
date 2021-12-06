#include<bits/stdc++.h>
using namespace std;

/*
要实现不使用额外空间且时间复杂度为 O(n)。

有点哈希表的意思了，以num[i]-1为下标给对应位置元素n，那么最后没有超过n的位置的下标就是不在数组中的数。
注意的地方是一个位置可能反复加n，所以要对元素-1取模。
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i ++){
            int tem = (nums[i]-1) % n;//注意要先减一再取模，先取模再减一会出现元素等于n，取完模等于0,再减一等于-1，出现数组越界的情况。
            nums[tem] += n;
        }
        for(int j = 0; j < n; j++){
            if(nums[j] <= n) res.push_back(j+1);
        }
        return res;
    }
};

