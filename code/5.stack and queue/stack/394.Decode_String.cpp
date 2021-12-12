#include<bit/stdc++.h>
using namespace std;
/*
从最内层开始解码
stack<pair<string,int>>保存每个数字前面的 字符串 和 数字 本身，后面遇到']'时，将res乘以栈顶的数字再加上，然后再被栈顶的res加上作为行动res
*/


class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>> st;
        int num = 0; string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] >='0' && s[i] <= '9'){
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '['){//压栈
                st.push(pair<string, int>(res, num));//保存状态，前面的res和接下来要扩展的倍数
                num = 0;
                res = "";
            }
            else if(s[i] == ']'){//出栈
                string tem = st.top().first;
                int rate= st.top().second;
                for(int i = 0; i < rate; i++){//[]内的字符串翻倍,然后加到栈顶的res上
                    tem += res;
                }
                res = tem;
                st.pop();
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};

