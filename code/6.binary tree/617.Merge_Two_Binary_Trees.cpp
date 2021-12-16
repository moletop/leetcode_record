
#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归
class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return NULL;
        if (!root1 || !root2) return root1 == NULL ? root2 : root1;

        TreeNode *node = root1;//如果是 TreeNode* node = new TreeNode() ：建立新树递归

        node->val = root1->val + root2->val;

        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);

        return node;
    }
};

//迭代

int main(){
    //建两棵树


    for(int i = 0; )

    for()
    //测试




}



