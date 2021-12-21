#include<bits/stdc++.h>

using namespace std;

//详情看代码，递归构造树


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
    unordered_map<int, int> map;//哈希表存中序的值和对应的下标，方便先序确定根节点之后，快速在中序中定位
    TreeNode *createTree(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il,
                         int ir) {//pl，pr为先序的左右边界下标。il，ir为中序的左右边界下标
        if (pl > pr) return NULL;//返回条件

        TreeNode *root = new TreeNode(preorder[pl]);//前序遍历中的第一个节点就是根节点
        int in_root = map[preorder[pl]];//在中序遍历中定位根节点
        root->left = createTree(preorder, inorder, pl + 1, in_root + pl - il, il,
                                in_root - 1);//递归左子树 ,x - (pl + 1) = (in_root - 1) - il ，解出x ，作为左子树新的pr
        root->right = createTree(preorder, inorder, in_root + pl - il + 1, pr, in_root + 1, ir);//递归右子树,x + 1作为右子树新的pl
        return root;
    }


    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();

        for (int i = 0; i < n; i++) map[inorder[i]] = i;
        TreeNode *res = createTree(preorder, inorder, 0, n - 1, 0, n - 1);
        return res;
    }
};

