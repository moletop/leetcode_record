#include<bits/stdc++.h>
using namespace std;
//求岛屿面积（1的个数）

/*
0-1矩阵(特别是岛屿问题) DFS模板。
多源深度DFS。
*/



class Solution {
public:
    int dfs(vector<vector<int>>& grid, int l, int r){
        int row_size = grid.size();
        int col_size = grid[0].size();
        if(l < 0 || l >= row_size || r < 0 || r >= col_size) return 0;//越界
        if(grid[l][r] !=1 ) return 0;
        grid[l][r] = 2;//遍历过的标记为2
        return (1 +    //上下左右
                dfs(grid, l - 1, r) +
                dfs(grid, l + 1,r) +
                dfs(grid , l, r - 1) +
                dfs(grid , l, r + 1));
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row_size = grid.size();
        int col_size = grid[0].size();
        int res = 0;
        for(int i = 0; i < row_size; i++){
            for(int j = 0; j < col_size; j++){
                res = max(dfs(grid, i, j), res);
            }
        }
        return res;

    }
};



