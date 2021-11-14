#include<bits/stdc++.h>
using namespace std;
//递归
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {//为什么要另外写一个函数，因为要迭代保存vec,函数内部定义vec的话，递归返回时内存会被释放掉。
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root,result);
        return result;
    }
};


//迭代
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if(!root) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            result.push_back(node->val);                                     // 中
            if(node->right) st.push(node->right);                           // 右
            if(node->left) st.push(node->left);                            // 左
        }
        return result;
    }
};
*/


