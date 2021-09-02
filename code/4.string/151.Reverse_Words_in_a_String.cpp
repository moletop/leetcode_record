#include <iostream>
#include <algorithm>
#include <vector>
#include<stack>
using namespace std;


//遇到翻转顺序或者相邻元素依次比较。应该首先想到栈。
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        // 去掉字符串开头的空白字符
        while (left <= right && s[left] == ' ') ++left;
        // 去掉字符串末尾的空白字符
        while (left <= right && s[right] == ' ') --right;

        stack<string> d;
        string word;

        while (left <= right) {
            char c = s[left];
            if (c != ' ') {
                word += c;
            }
            if (c == ' '&&word.size()) {
                // 将单词 push 到队列的头部
                d.push(move(word));
                word = "";
            }

            ++left;
        }
        d.push(move(word));


        string ans;
        while (!d.empty()) {
            ans += d.top();
            d.pop();
            if (!d.empty()) ans += ' ';//最后一个元素还不加空格，非常巧妙
        }
        return ans;
    }
};


int main(){
    Solution solution;
    string s="     the mother     is blue    ";
    s=solution.reverseWords(s);
    cout<<s;


    return 0;
}

