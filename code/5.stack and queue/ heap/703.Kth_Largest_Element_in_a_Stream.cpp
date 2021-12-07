#include<bits/stdc++.h>
using namespace std;

//优先队列基础题，如果用普通sort会超时。
//第k大的元素：维持大小为k的最小堆。


class KthLargest {
public:
    int count;
    priority_queue<int,vector<int>, greater<int>> que;//最小堆

    KthLargest(int k, vector<int>& nums) {
        count = k;
        int num = nums.size();
        for( int i = 0 ; i < num; i++){
            que.push(nums[i]);
        }
    }

    int add(int val) {

        que.push(val);
        while(que.size() > count) que.pop();
        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

