#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    string multiply(string nums1, string nums2){
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(m + n , 0);
        for(int i = m - 1; i >= 0; i --){
            for(int j = n -1; j >= 0; j --){
                int sum = (nums1[i] - '0') * (nums2[j] - '0');
                int high = i + j; int low = i + j + 1;//算出当前高低位
                sum += res[low];//加上当前低位（就是上一步操作的高位）
                res[low] = sum % 10;
                res[high] += sum / 10;// 注意这里要+=

            }
        }

        string s = "";
        for(int i = 0; i < res.size(); i ++){
            if(!(res[i] == 0 && s.size() == 0))//逻辑注意
                s += to_string(res[i]);
        }
        return s.size() == 0? "0" : s;
    }
};
