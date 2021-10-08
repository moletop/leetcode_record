#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1;
        stack<int> st;
        for (const char& c : s) {
            if (isdigit(c)) {
                num = 10 * num + (c - '0');
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        res += sign * num;
        return res;
    }
};