#include<bits/stdc++.h>

using namespace std;


// 贪心，攻击从大到小排序，防御从小到大排序。
//然后顺序遍历，每次存储防御最大的值。

using namespace std;
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pr) {
        sort(pr.begin(),pr.end(),[&](auto &a,auto &b){
            return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];  //排序
        });
        int ans = 0, high = INT_MIN;
        for(auto& x: pr) high > x[1] ? ++ans : high = x[1];
        return ans;
    }
};



int main(){
    Solution solution;
    vector<vector<int>>nums={{5,5},{6,3},{3,6},{5,3},{5,6}};
    int res= solution.numberOfWeakCharacters(nums);
    cout<<res<<endl;
    return 0;
}