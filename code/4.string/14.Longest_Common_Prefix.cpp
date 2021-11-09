#include<bits/stdc++.h>
using namespace std;
/*
 * 字符串基础操作题，模拟过程。 第一个思想是逐个两两比较，产生的公共前缀和下一个单词继续比较，直到最后得到答案
 * 这里也可以纵向比较，按照第一个单词的逐个字母和后面单词对应的逐个字母对比
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs[0].size();
        int size = strs.size();
        int flag =0;
        int i;//提前申明，以免i是局部变量，跳出循环之后就用不了。
        for(i = 0 ; i < length ; i++){
            char ans = strs[0][i];
            int j;
            for(j = 1; j < size && strs[j][i] == ans ; j++);//不用担心strs[j][i] 中i越界的情况，字符串后面有个'\0'
            if(j != size)   break;
        }
        return strs[0].substr(0 ,i);
    }
};
//骚操作,直接字符串排序，然后第一个和最后一个取最小公共前缀


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return string();
        sort(strs.begin(), strs.end());
        string st = strs.front(), en = strs.back();
        int i, num = min(st.size(), en.size());
        for(i = 0; i <  num && st[i] == en[i]; i ++);
        return string(st, 0, i);
    }
};

