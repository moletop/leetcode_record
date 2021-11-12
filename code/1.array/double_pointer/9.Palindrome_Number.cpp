#include<bits/stdc++.h>
using namespace std;

//典型双指针

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;

        string s = to_string(x);

        int l = 0; int r = s.size() - 1;
        for(;l <= r;){
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else return false;
        }
        return true;

    }
};
