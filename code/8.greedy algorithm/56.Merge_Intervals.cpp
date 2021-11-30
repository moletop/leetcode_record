#include<bit/stdc++.h>
using namespace std;

/*
排好序后，当前的左区间小于前一个的右区间时，修改前一个的右区间(贪心)：
max(res[res.size()-1][1],intervals[i][1]);
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;

        vector<vector<int>> res;//结果存储
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){//遍历
            if(intervals[i][0] <= res[res.size()-1][1]){//当前的左区间小于前一个的右区间时，修改结果数组中最后一个的右区间
                res[res.size()-1][1] = max(res[res.size()-1][1],intervals[i][1]);
            }
            else res.push_back(intervals[i]);
        }
        return res;
    }
};

