#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {

        vector<int> res;
        if(k==0) return res;
        priority_queue<int>p;
        for (int i = 0; i < k; ++i) {
            p.push(arr[i]);
        }
        for (int i = k; i <arr.size() ; ++i) {
            if(arr[i]<p.top()){
                p.pop();
                p.push(arr[i]);
            }
        }
        for (int i = 0; i <k ; ++i) {
            res.push_back(p.top());
            p.pop();
        }
        return res;
    }
};
