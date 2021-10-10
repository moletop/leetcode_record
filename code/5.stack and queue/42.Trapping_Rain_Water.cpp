#include<bits/stdc++.h>
using namespace std;

//单调栈模板，具体可看官方单调栈解析
class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        stack<int>st;
        for (int i = 0; i <height.size() ; ++i) {
            while(!st.empty()&&height[st.top()]<height[i]){
                int top = height[st.top()];
                st.pop();
                if(!st.empty()){
                    int left = st.top();
                    res += (i - left - 1) * (min(height[left], height[i]) - top);//i-left-1是水柱宽度，min(height[left], height[i]) - top是水柱高度
                }
                else break;
            }
            st.push(i);

        }
        return res;
    }
};


