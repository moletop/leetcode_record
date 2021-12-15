#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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
    TreeNode* build(TreeNode* root, int val){
        if(root == NULL){
            root = new TreeNode();
            root->val = val;
            return root;
        }
        if(val < root->val) root->left = build(root->left, val);
        else if(val > root->val) root->right = build(root->right, val);
        return root;
    }


    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        vector<int> vec;
        if (cur == NULL) return vec;
        vec.push_back(cur->val);
        preorderTraversal(cur->left);
        preorderTraversal(cur->right);
    }
};


int main(){
    Solution solution;
    TreeNode * t;


    int node_value[5]={1,NULL,2,3};
    for (int i = 0; i < 5 ;++i) {
        t= solution.build(t,node_value[i]);
    }


    return 0;
}