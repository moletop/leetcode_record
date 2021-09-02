#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

//单调栈模板,然后加限制条件
//单调栈 ,n-k的栈 ,最左pop k次
class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        for (int i = 0; i < num.size(); ++i) {
            while(!s.empty()&&num[i]<s.back()&&k>0){//单调栈加了一个最多pop k次的条件
                s.pop_back();
                k--;
            }
            s+=num[i];
        }

        //如果没有删除k次,从后面依次pop()够次数
        if(k>0){
            for (int i = 0; i < k; ++i) {
                s.pop_back();
            }
        }

        //删除掉开头的零
        while(!s.empty()&&s.front()=='0')
            s.erase(0,1);

        if(s.empty()) return "0";
        return s;
    }
};

