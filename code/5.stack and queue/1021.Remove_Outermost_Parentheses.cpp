#include<bits/stdc++.h>
using namespace std;
//经典的字符串匹配，这题的输出点在栈为空时，将最后匹配括号之间的内容添加到结果字符中
class Solution {
public:
    string removeOuterParentheses(string s) {

        int n = s.size();
        if(n < 2)  return s;

        stack<int> stk;
        string res = "";
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') stk.push(i);
            else{
                int tem = stk.top(); stk.pop();
                if(stk.empty())  res += s.substr(tem + 1 ,i - tem - 1);
            }
        }
        return res;
    }
};

