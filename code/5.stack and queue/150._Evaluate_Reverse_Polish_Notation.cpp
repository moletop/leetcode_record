#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if (tokens[i] == "+") stk.push(num2 + num1);
                if (tokens[i] == "-") stk.push(num2 - num1);
                if (tokens[i] == "*") stk.push(num2 * num1);
                if (tokens[i] == "/") stk.push(num2 / num1);
            } else {
                    stk.push(stoi(tokens[i]));
            }
        }
        int result = stk.top();
        stk.pop();
        return result;


    }
};


int main() {
    vector<string> tokens;
    tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution solution;
    int result =solution.evalRPN(tokens);
    cout<<result<< endl;


    return 0;
};