#include<bitc/stdc++.h>
using namespace std;
/*
核心：static bool cmp(string a, string b){
    return a+b <b+a;
}
*/



class Solution {
public:
    static bool cmp(string a, string b){
        return a+b <b+a;
    }

    string minNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return " ";
        if(n ==1) return to_string(nums[0]);
        vector<string> res;
        for(int i = 0; i < n; i++) res.push_back(to_string(nums[i]));
        sort(res.begin(),res.end(),cmp);
        string ans = res[0];
        for(int i = 1; i < res.size(); i++) ans += res[i];
        return ans;
    }
}

