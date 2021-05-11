#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};

int main(){
    string s ("abcdef");
    int n =2;
    Solution solution ;
    string s_reverse = solution.reverseLeftWords(s,n);
    cout<< s_reverse << endl;
    return 0;

}
