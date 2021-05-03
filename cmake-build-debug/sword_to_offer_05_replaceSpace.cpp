#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int old_size = s.size();
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                count++;
            }
        }
        s.resize(s.size() + 2 * count);
        int new_size = s.size();
        for (int i = new_size, j = old_size; j < i; j--, i--) {
            if (s[j]==' ') {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] ='%';
                i-=2;
            } else {
                s[i] = s[j];
            }
        }
        return s;
    }
};


int main() {
    string s = "hello boys and girls";
    Solution solution;
    string s_after = solution.replaceSpace(s);
    for (int i = 0; i < s_after.size(); ++i) {
        cout<<s_after[i]<<endl;
    }
    return 0;
}