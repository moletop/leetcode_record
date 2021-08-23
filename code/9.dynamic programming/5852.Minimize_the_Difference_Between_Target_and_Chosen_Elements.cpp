#include<iostream>
#include<vector>
#include <algorithm>
#include<bitset>
using namespace std;

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& A, int target) {
        int n=A.size();
        int m=A[0].size();
        bitset<5000> F[n];
        F[0]=0;
        for (int i=0;i<m;++i) F[0][A[0][i]]=1;
        for (int i=1;i<n;++i)
        {
            F[i]=0;
            for (int j=0;j<m;++j) {
                F[i] |= F[i - 1] << A[i][j];
            }
        }
        int ans=4900;
        for (int i=1;i<=4900;++i)
            if (F[n-1][i])
                ans=min(ans,abs(target-i));
        return ans;
    }
};



int main() {
    vector<vector<int>> mat;
    int target = 0;
    Solution solution;
    int tem;
    vector<int> vec;
    for (int i = 0; i < 3; i++) {
        vec.clear(); //每次要clear
        for (int j = 0; j <3; j++) {
            cin >> tem;
            vec.push_back(tem);
        }
        mat.push_back(vec);
    }

    scanf("%d", &target);
    int result = solution.minimizeTheDifference(mat, target);
    printf("%d", result);
    return 0;
}