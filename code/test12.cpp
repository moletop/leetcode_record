#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        int res = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        queue<pair<int,int>> que;

        if(k == 0) return res;
        int x = 0,y = 0;
        dp[x][y] = 1;que.push(make_pair(x, y));
        int x_move[2] = {1, 0};
        int y_move[2] = {0, 1};

        while(!que.empty()){
            x = que.front().first;
            y = que.front().second;
            for(int i = 0; i < 2; i++){
                int temx = x + x_move[i];
                int temy = y + y_move[i];
                if(temx < m && temy < n && count(temx,temy) <= k && dp[temx][temy] == 0){
                    que.push(make_pair(temx, temy));
                    dp[temx][temy] = 1;
                    res++;
                }
            }
            que.pop();
        }
        return res;
    }
};
