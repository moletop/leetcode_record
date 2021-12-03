#include<bits/stdc++.h>
using namespace std;

//左上交判定条件
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[i].size();j++){
                if((i==0||land[i-1][j]==0) && (j==0||land[i][j-1]==0) && land[i][j]==1)//左上交
                {
                    int right=j;
                    while(right<land[i].size()&&land[i][right]==1)right++;
                    int down=i;
                    while(down<land.size()&&land[down][j]==1)down++;

                    ans.push_back(vector<int>({i,j,down-1,right-1}))
                }
            }
        }
        return ans;
    }
};