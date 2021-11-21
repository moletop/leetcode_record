#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size() ; ++i) {
            if(s[i]== '{'){
                stk.push('}');
            }
            else if(s[i]=='['){
                stk.push(']');
            }
            else if(s[i]=='('){
                stk.push(')');
            }
            else if(stk.empty()||stk.top()!=s[i]){
                return false;
            }
            else{
                stk.pop();
            }
        }
        if(stk.empty()){
            return true;
        }
        else return false;
    }
};



int main(){
    string s;
    cin>> s;
    Solution solution;
    cout<<solution.isValid(s)<<endl;
    return 0;
}