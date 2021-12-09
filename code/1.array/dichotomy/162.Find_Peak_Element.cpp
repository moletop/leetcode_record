#include<bits/stdc++.h>
using namespace std;
/*
关键条件：两边都是负无穷。

数组当中可能有很多波峰，也可能只有一个，如果尝试画图，就跟股票信息一样，没有规律。可以根据中点値判断我们的二分方向该往何处取。

中点所在地方，可能是某座山的山峰，山的下坡处，山的上坡处，如果是山峰，最后会二分终止也会找到，关键是二分方向。

我们开始并不知道山峰在我们左边还是右边，就像爬山。

如果你往下坡方向走，也许可能遇到新的山峰，但是也许是一个一直下降的坡，最后到边界。
但是如果你往上坡方向走，就算最后一直上的边界，由于最边界是负无穷，所以就一定能找到山峰，总的一句话，往递增的方向上，二分，一定能找到，往递减的方向只是可能找到，也许没有。

*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0; int r = n - 1;
        for(; l < r ; ){
            int mid = l + (r - l)/2;
            if(nums[mid] > nums[mid+1])  r = mid
            else l = mid + 1;
        }
        return l;
    }
};


