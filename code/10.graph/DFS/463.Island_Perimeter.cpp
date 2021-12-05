#include<bits/stdc++.h
using namespace std;
//求岛屿周长
/*对每一个陆地格子往外扩展，当是网格的边界或者水域（0）时，表示增加一条边。
如果是已经标记的2，则不需要增加。
如果是1,则标记为2, 继续向下遍历。

也是0-1矩阵DFS的模板稍加改动
*/


class Solution {
public:
    int dfs(vector<vector<int>> & grid, int l, int r){
        if(l < 0 || l >= grid.size() || r < 0 || r >= grid[0].size()) return 1;
        if(grid[l][r] == 0) return 1;
        if(grid[l][r] == 2) return 0;
        grid[l][r] = 2;
        return (dfs(grid, l - 1, r) +dfs(grid, l + 1, r) + dfs(grid, l, r - 1) + dfs(grid, l, r + 1));//上下左右
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                res = max(dfs(grid, i , j), res);
            }
        }
        return res;
    }
};
