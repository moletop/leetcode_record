#include<bits/stdc++.h>
using namespace std;


//递归
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中

    }
    vector<int> postorderTraversal(TreeNode* root) {
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
            TreeNode* node = st.top(); st.pop();    // 中
            result.push_back(node->val);
            if(node->left) st.push(node->left);         // 左
            if(node->right) st.push(node->right);       // 右


        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};
*/







