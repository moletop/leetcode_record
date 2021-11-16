
#include<bits/stdc++.h>
using namespace std;

 /*

set的妙用，让每次查询的复杂度为O(1);整体复杂度为O(n);

先遍历一遍存进set。
然后遍历第二遍,如果i-1在set中，说明i不是最小的，所以不用从他开始遍历。
反之，就从他开始逐次加1看是否在set中，最后记录最长的长度。

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++){
            set.insert(nums[i]);
        }
        for(auto i: set){
            if(!set.count(i - 1)) {
                int tem = i;
                while(set.count(tem + 1)) tem++;
                res = max(res , tem - i + 1);
            }
        }
        return res;
    }
};
