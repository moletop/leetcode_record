#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        string v =" ";
        for (int i = 0; i < s.size(); ++i) {
            v+= s[i];

        }
        reverse(v.begin(),v.end());
        for (int i = 0; i < v.size(); ++i) {
            s[i]=v[i];
        }
    }
};


int main(){
    Solution solution;
    vector<char> s = {'s','h','o','y'};
    string v =" ";
    for (int i = 0; i < ; ++i) {
        v+= s[i];

    }

   solution.reverseString(s);
    for (int i = 0; i <s.size() ; ++i) {
        cout<<s[i]<<" "<<endl;
    }
    return 0;
}


