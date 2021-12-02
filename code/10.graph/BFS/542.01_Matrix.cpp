#include<bits/stdc++.h>
using namespace std;


/*解题思路
求所有1到最近0的距离 ，抽象成从0出发，多源广度优先遍历（使用队列）
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> res(m ,vector<int>(n ,-1));//结果矩阵先全赋值为-1
        queue<pair<int,int>> que;

        for(int i = 0 ; i < m ; i++){//把位置全为0的位置更新为0，并且入队列
            for(int j = 0; j < n ; j++){
                if(mat[i][j] == 0) {
                    que.push(pair<int,int>(i , j));
                    res[i][j] = 0;
                }
            }
        }

        int x_count[4] = {-1 , 1 , 0 , 0};
        int y_count[4] = {0 , 0 , -1 , 1};//上下左右遍历
        while(!que.empty()){
            auto tem = que.front(); que.pop();
            int x = tem.first;
            int y = tem.second;
            for(int i = 0 ; i < 4 ; i++){
                int newX = x + x_count[i];
                int newY = y + y_count[i];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && res[newX][newY] == -1){
//如果上下左右遍历的坐标不越界，而且遍历到了-1，则在遍历初始点的基础上加1，且将遍历点加入队列
                    res[newX][newY] = res[x][y] +1;
                    que.push(pair<int, int>(newX ,newY));
                }
            }
        }
        return res;
    }
};

