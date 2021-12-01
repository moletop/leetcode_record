#include<bits/stdc++.h>

using namespace std;


/*
   在 77.组合 的基础上，
   限定了一共1-9这9个数，这是树的搜索的宽度，k个数依旧是深度，然后加了一个限制，路径的和等于n;
   套用回溯模板可解决。
 */


class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(int k, int n, int start) {
        /*
        k : k个数的和
        n : 目标和
        start : 递归起点
        */
        if (path.size() == k) {
            if (n == 0) res.push_back(path);
            return;
        }
        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            n -= i;
            dfs(k, n, i + 1);
            path.pop_back();
            n += i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }
};

