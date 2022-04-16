#include<bits/stdc++.h>

using namespace std;

/*
最小堆
*/



vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> res;
    int n = nums.size();
    map<int, int> map;
    for (auto i : nums) map[i]++;

    using pi = pair<int, int>;
    priority_queue<pi, vector<pi>, greater<pi>> minheap;
    for (auto i : map) {
        if (minheap.size() == k) {
            if (minheap.top().first < i.second) minheap.pop();
            else continue;
        }
        minheap.push(pair<int, int>(i.second, i.first));
    }

    while (minheap.size()) {
        res.push_back(minheap.top().second);
        minheap.pop();
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3, 1,  3, 4, 1};
    vector<int> res;
    res = topKFrequent(nums, 2);
    for(auto i : res){
        printf("%d",i);
    }
    return 0;
}


