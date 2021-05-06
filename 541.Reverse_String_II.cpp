#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int count = s.size();
        for (int i = 0; i < count ; i += (2*k)) {
            if(i+k < count){
                reverse(s.begin()+i,s.begin()+i+k);
            }
            else{
                reverse(s.begin()+i,s.begin()+count);
            }
        }
        return s;
    }
};


int main(){
    string s ="abcd";
    int k =2;
    Solution solution;
    string s_reverse = solution.reverseStr(s,k);
    cout << s_reverse <<endl;
    return 0;
}



