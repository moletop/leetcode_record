#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp (string &a, string &b){
        if(a.size()==b.size()) return  a>b;
        return a.size() > b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(),cmp);
        string s = nums[k-1];
        return s;
    }
};

