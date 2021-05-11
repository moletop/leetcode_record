#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        for (char s:S) {
            if (stk.empty() || s != stk.top()) {
                stk.push(s);
            } else {
                stk.pop();
            }
        }

        string result = "";
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    string s = "abbaca";
    Solution solution;
    string result = solution.removeDuplicates(s);
    cout << result << endl;

    return 0;

}

