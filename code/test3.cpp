#include <iostream>
#include <queue>
#include<cstring>
#include <algorithm>
#include<cmath>
#include<set>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> a;
        for (auto& i : nums) {
            a.emplace(i);
        }
        int n = nums[0].size();
        for (int i = 0; i < (1 << n); ++i) {
            string x(n, '0');
            for (int j = 0; j < n; ++j) {
                x[j] = (1 & (i >> j)) + '0';
            }
            if (a.find(x) == a.end()) {
                return x;
            }
        }
        return string(n, '0');
    }
};
int main(){
    Solution solution;
    vector<string>vec ={"101","000","111"};
    string s=solution.findDifferentBinaryString(vec);
    cout<<s<<endl;

    return 0;
}