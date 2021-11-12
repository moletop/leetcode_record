#include<bits/stdc++.h>
using namespace std;

/*
注意这里for循环，不像是在：77.组合！和216.组合总和III中从start开始遍历的。

因为本题每一个数字代表的是不同集合，也就是求不同集合之间的组合，而前面两个都是是求同一个集合中的组合！

总结:回溯法中的参数，要能提供树的初始宽度和递归深度信息，还有每一次递归的起点这个参数
*/



class Solution {
public:
    vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string path;
    vector<string> res;

    void dfs(string& digits, int level){
        if(path.size() == digits.size()){//递归终止条件
            res.push_back(path);
            return;
        }
        int num = digits[level]-'0';//转成数字，对应table的下标，用来提取数字对应的字符集合
        for(int i = 0; i < table[num].size(); i++){//对每一个字符集合遍历
            path.push_back(table[num][i]);//操作
            dfs(digits, level +1);//向下递归
            path.pop_back();//回溯
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        dfs(digits, 0);
        return res;
    }
};

