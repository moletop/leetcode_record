#include<bits/stdc++.h>
using namespace std;
/*
思路参考：
https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
1.先找一个递增相邻数对（i,j），
2.然后（j,end）区间从后往前遍历找第一个比nums[i]大的数nums[k]，并且交换nums[i]与nums[k]。
3.将（j,end）从小到大排列。
*/

class Solution{
public:
    void nextPermutation(vector <int> & nums){
        int n = nums.size();
        if(n <= 1) return;
        int i = n - 2, j = n - 1, k = n - 1;
        //find A[i] < A[j]
        while(i >= 0 && nums[i] >= nums[j]){
            --i, --j;
        }
        if(i >= 0){
            //find A[i] < A[k]
            while( nums[i] >= nums[k]) --k;
            swap(nums[i], nums[k]);
        }
        reverse(nums.begin() + j, nums.end());
    }
};

