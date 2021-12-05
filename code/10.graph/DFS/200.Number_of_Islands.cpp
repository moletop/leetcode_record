#include<bits/stdc+.h>
using namespace std;

//求岛屿个数（1组成的陆地的块数）

/*
0-1矩阵(特别是岛屿问题) DFS模板。
多源深度DFS，已经遍历过的标记成2。
*/

代码

class Solution {
public:
    void dfs(vector<vector<char>>&grid, int l , int r){//注意要取地址符，因为要修改矩阵内容返回
        if(l < 0 || l >= grid.size() || r < 0 || r >= grid[0].size()) return ;
        if(grid[l][r] != '1') return;
        grid[l][r] = '2';//标记为2
        dfs(grid, l, r - 1);
        dfs(grid, l, r + 1);
        dfs(grid, l - 1, r);
        dfs(grid, l + 1, r);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid, i , j);
                }
            }
        }
        return res;
    }
};

