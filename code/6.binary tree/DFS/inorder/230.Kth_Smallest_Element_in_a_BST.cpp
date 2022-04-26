#include<bits/stdc++.h>
using namespace std;

//230. 二叉搜索树中第K小的元素
//二叉搜索树的中序遍历是递增有序的

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        vector<int> path;

        while(root || !stk.empty()){
            while(root){//指针用来访问节点。访问到最底层
                stk.push(root);//将访问的节点放进栈
                root = root -> left;//左
            }
            root = stk.top(); stk.pop();
            path.push_back(root -> val);//中
            if(path.size() == k) return root -> val;
            root = root -> right;//右
        }
        return 0;
    }
};