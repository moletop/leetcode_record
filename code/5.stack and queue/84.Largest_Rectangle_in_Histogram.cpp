#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        vector<int> cp=heights;
        cp.push_back(0);
        int n=cp.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&cp[st.top()>cp[i]]){
                int cur= st.top();st.pop();
                if(!st.empty()){
                    int l=st.top()+1;
                    int r =i-1;
                    res=max(res,cp[cur]*(l-r+1));
                }
            }
            st.push(i);
        }
        return res;
    }
};