include<bits/stdc++.h>
using namespace std;

//参考大神的思路：右上角为根节点，就转化成一棵二叉搜索树。


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        if(matrix.size() == 0) return false;
        int i = 0; int j = matrix[0].size() - 1;
        for(;i <matrix.size() && j >= 0; ){
            if(matrix[i][j] > target) j--;
            else if(matrix[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};
