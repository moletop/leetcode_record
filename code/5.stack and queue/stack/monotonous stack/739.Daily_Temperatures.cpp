#include<bits/stdc++.h>
using namespace std;
//单调栈（递减）
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        stack<int> st;
        for (int i = 0; i <n ; ++i) {
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                int tem=st.top();
                st.pop();
                res[tem]=i-tem;
            }
            st.push(i);
        }
        return res;
    }
};

