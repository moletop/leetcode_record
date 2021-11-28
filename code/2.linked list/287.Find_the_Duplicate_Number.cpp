#include<bit/stdc++.h>
using namespace std;

/*
借鉴大佬思路：
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/287xun-zhao-zhong-fu-shu-by-kirsche/
类比142题：环形链表II
 (Floyd Cycle Detection Algorithm),又称龟兔赛跑算法(Tortoise and Hare Algorithm）
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int ptr1 = 0;
        int ptr2 = slow;
        while(ptr1 != ptr2){
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};

