#include<bits/stdc++.h>

using namespace std;
//树 ，dfs（后序）递归
//和树的深度如出一辙

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = 0;//全局变量
    int depth(TreeNode *root) {
        if (!root) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        ans = max(ans, l + r + 1);//在后序遍历途中顺便完成题目的要求
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        ans = 0;
        depth(root);
        return ans - 1; //需要减1 ，不然是节点数
    }
};

