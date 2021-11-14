#include<bits/stdc++.h>
using namespace std;

//递归
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中
        traversal(cur->right, vec); // 右
    }
    vector<int> midorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root,result);
        return result;
    }
};

//迭代

/*
因为前序遍历的顺序是中左右，先访问的元素是中间节点，要处理的元素也是中间节点，所以刚刚才能写出相对简洁的代码，因为要访问的元素和要处理的元素顺序是一致的，都是中间节点。

再看看中序遍历，中序遍历是左中右，先访问的是二叉树顶部的节点，然后一层一层向下访问，直到到达树左面的最底部，再开始处理节点（也就是在把节点的数值放进result数组中），这就造成了处理顺序和访问顺序是不一致的。

所以前面写的前序遍历的迭代代码，不能和中序遍历通用。(例子：5，4，6，1，2)
*/
/*
class Solution {
public:
    vector<int> midorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {//指针遍历来帮助访问节点，栈则用来处理节点上的元素。
            while (root != nullptr) {//指针用来访问节点。访问到最底层
                stk.push(root);//将访问的节点放进栈
                root = root->left;//左
            }
            root = stk.top();// 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
            stk.pop();
            res.push_back(root->val);//中
            root = root->right;//右
        }
        return res;
    }
};
//中序遍历的时候栈的深度取决于二叉搜索树的高度
*/



