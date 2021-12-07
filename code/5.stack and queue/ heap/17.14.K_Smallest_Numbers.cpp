#include<bits/stdc++.h>
using namespace std;

//k个最小的数，维护一个大小为k的最大堆，把大的数都弹出去。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {

        vector<int> res;
        if(k==0) return res;
        priority_queue<int> que;
        for (int i = 0; i < arr.size(); ++i) {
            if(que.size() < k) que.push(arr[i]);
            else{
                if(arr[i] < que.top()) {que.pop(); que.push(arr[i]);}
            }
        }
        while(!que.empty()){
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }
};