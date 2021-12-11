#include<bits/stdc++.h>
using namespace std;

public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int major = 0; int count = 0;
        for(auto i : nums){
//典型用哈希优化复杂度

            class Solution {
            map[i]++;
            if(map[i]>count) {count = map[i]; major = i;}
        }
        return major;
    }
};





