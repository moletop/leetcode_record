#include<bits/stdc++.h>
using namespace std;
//要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置  通常使用单调栈。
//这边为了加快运行速度，使用的map来查询。
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        stack<int> st;

        map<int,int>m;

        for(int i=0;i<nums2.size();i++){//单调栈模板
            while(!st.empty()&&nums2[i]>nums2[st.top()]){
                int tem= st.top();st.pop();
                m.insert(pair<int,int>(nums2[tem],nums2[i]));
            }
            st.push(i);
        }

        for(int i=0;i<nums1.size();i++){
            if(m.find(nums1[i])!=m.end()) res.push_back(m[nums1[i]]);
            else res.push_back(-1);

        }
        return res;
    }
};
