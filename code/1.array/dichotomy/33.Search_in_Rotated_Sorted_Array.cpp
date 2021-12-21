#include<bits/stdc++.h>
using namespace std;

/*
旋转过的数组，任意切一刀，一定有一边是有序的。

mid就是那一刀。

然后看target是否在有序的那一段中，如果是，在有序的那一段继续同样方式找
        如果不在，就在无序的那段中找。

也相当于一个二分。

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;

        while(l <= r){//一定要写等号，
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return mid;

            if(nums[l] <= nums[mid]){//一定要等号，l = r时可以进入，然后改变l或者r的状态，最后跳出while循环
                if(nums[l] <= target && nums[mid] >= target){
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            else{
                if(nums[mid] <= target && nums[r] >= target){
                    l = mid + 1;
                }
                else  r = mid - 1;
            }
        }
        return -1;
    }
};


