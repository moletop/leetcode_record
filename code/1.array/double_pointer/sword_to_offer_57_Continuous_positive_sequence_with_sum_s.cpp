#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
双指针

1.如果左右指针之间和超过target,左指针右移.
2.如果左右指针之间和小于target,右指针右移.
3.如果左右指针之间和等于target,把左右之间的数加入到结果中,然后别忘了左指针右移.

*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>res;
        vector<int>tem;
        int sum=0;
        for ( int l=1,r=2; l <r ; ) {
            sum = (l + r) * (r - l + 1) / 2;//直接用公式计算.复杂度为O(1)
            if(sum==target) {
                tem.clear();
                for (int i = l; i<=r ; i++) {
                    tem.push_back(i);
                }
                res.push_back(tem);
                l++;
            }
            else if(sum<target) r++;
            else l++;
        }
        return res;
    }
};

