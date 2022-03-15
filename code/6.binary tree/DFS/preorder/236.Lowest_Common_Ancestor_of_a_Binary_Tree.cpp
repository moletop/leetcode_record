#include<bits/stdc++.h>
using namespace std;

/*
二叉树的最近公共祖先节点
和二叉搜索树的最近公共祖先节点注意区分

借鉴k神思路：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/
先序dfs
终止条件：
1.当越过叶节点，则直接返回 null ；
2.当 root 等于 p, q ，则直接返回 root ；

递推工作：
1.开启递归左子节点，返回值记为 left ；
2.开启递归右子节点，返回值记为 right ；
3.返回值： 根据 left 和 right ，可展开为四种情况；
    1.当 left 和 right 同时为空 ：说明 root 的左 / 右子树中都不包含 p,q，返回 null ；
    2.当 left 和 right 同时不为空 ：说明 p, q 分列在 root 的 异侧 （分别在 左 / 右子树），因此 root 为最近公共祖先，返回 root ；
    3.当 left 为空 ，right 不为空 ：p,q 都不在 root 的左子树中，直接返回 right 。具体可分为两种情况：
        p,q 其中一个在 root 的 右子树 中，此时 right 指向 p（假设为 p ）；
        p,q 两节点都在 root 的 右子树 中，此时的 right 指向 最近公共祖先节点 ；
    4.当 left不为空 ， right 为空 ：与情况 3. 同理；
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL || root == p || root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (!left && !right) return NULL;
        if (!left) return right;
        if (!right) return left;
        return root;
    }
};

