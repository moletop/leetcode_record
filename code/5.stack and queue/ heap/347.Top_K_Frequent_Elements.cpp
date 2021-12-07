#include<bits/stdc++.h>
using namespace std;
/*
最小堆
*/


class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){//第二个元素的最小堆
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        map<int,int> map;
        for(int i = 0; i < nums.size(); i++){//哈希表统计次数
            map[nums[i]]++;
        }
        vector<pair<int,int>> ans(map.begin(), map.end());//map转vector<pair<int, int>>
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> que(cmp);//元素为pair的优先队列，并设置排序规则。

        for(auto i : ans){//维持大小为K的最小堆
            if(que.size() < k) que.push(i);
            else{
                if(i.second>que.top().second) {que.pop(); que.push(i);}
            }
        }
        while(!que.empty()){//取结果
            res.push_back(que.top().first);
            que.pop();
        }
        return res;
    }
};

