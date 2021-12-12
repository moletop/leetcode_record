#include<bits/stdc++.h>
using namespace std;


//回溯模板:
//这里不再设置全局类变量 res和path，他们直接作为参数传入递归函数。res存结果（使用地址引用），path使用值引用，利用系统栈完成递归和回溯。



class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrace(res, "", n, 0, 0);
        return res;

    }
    void backtrace(vector<string> &res, string path, int n, int l, int r){
        if(l > n || l < r) return ;
        if(l == r && l == n){
            res.push_back(path);
            return;
        }
        backtrace(res, path + '(', n, l + 1, r);
        backtrace(res, path + ')', n, l, r + 1);

    }


};


