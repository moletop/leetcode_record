
#include<bits/stdc++.h>
using namespace std;
/*
此题如果不考虑满足常数空间，有很多方法，如哈希表统计各个数字的个数，然后按顺序复现数组，或者直接调用排序算法。

为了满足常数空间的消耗，设立双指针，strat在开头，用来交换0，end在结尾，用来交换2.

两点需要注意的地方：

1.因为遍历顺序为从左到右，所以交换0时，可以保证与下标start的数字交换时，换过来的一定不是0。但是2在末尾，与下标end的数字交换时,end下标的数字可能自己就是2，所以换过来本位还是2，所以要循环处理，直到本位不是2为止。
2.要先判断2，再判断0。因为，2交换到end下标时，可能换回来一个0。
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int start = 0;
        int end = size - 1;
        for(int i = 0; i <= end; i++){
            while(i<end && nums[i]== 2){
                swap(nums[i],nums[end]);
                end--;
            }
            if(nums[i] == 0){
                swap(nums[i],nums[start]);
                start++;
            }
        }
    }
};

