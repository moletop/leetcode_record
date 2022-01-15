#include<bits/stdc++.h>
using namespace std;

//解题思路:双指针
//亮点在原地修改，从nums1的后面开始填


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, cur = m + n -1;

        while(i >= 0 &&j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[cur] = nums1[i];
                cur--;i--;
            }
            else{
                nums1[cur] = nums2[j];
                cur--; j--;
            }
        }

        if(i < 0) {
            while(j >= 0){
                nums1[cur] = nums2[j];
                cur--; j--;
            }
        }
        else{
            while(i >= 0){
                nums1[cur] = nums1[i];
                cur--;i--;
            }
        }
        return;
    }
};

