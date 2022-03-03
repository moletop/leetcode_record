#include<bits/stdc++.h>
using namespace std;


//二叉搜索树的最近公共祖先

/*
本题给定了两个重要条件：① 树为 二叉搜索树 ，② 树的所有节点的值都是 唯一 的。根据以上条件，可方便地判断p,q 与 root 的子树关系，即：

若 root.val < p.val ，则 p 在 root右子树 中；
若 root.val > p.val ，则 p 在 root左子树 中；
若 root.val = p.val ，则 p 和 root指向 同一节点 。

方法一：迭代
        循环搜索： 当节点 root 为空时跳出；
当 p,q 都在 root 的 右子树 中，则遍历至 root.right ；
否则，当 p, q 都在 root 的 左子树 中，则遍历至 root.left；
否则，说明找到了 最近公共祖先 ，跳出。
返回值： 最近公共祖先 root 。
*/


struct TreeNode {
   int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p ->val > root->val && q->val > root->val) root = root -> right;
            else if(p->val < root->val && q->val <root->val) root = root -> left;
            else break;
        }
        return root;
    }
};