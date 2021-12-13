#include<bits/stdc++.h>
using namespace std;

//滑动窗口内 维护一个哈希表，一旦右边发现有重复的字符，从左边收缩窗口，直到左边重复字符弹出窗口，然后右边窗口再扩张。



class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0) return 0;

        unordered_map<char,int> map;
        int res =0;//结果
        int i, j;//左右窗口的指针
        for(i = 0, j = 0; j < size && i <= j; j++){
            if(!map.count(s[j])){
                map[s[j]] = 1 ;
                res = max(res, j - i +1);
            }
            else{
                while(map.count(s[j])){
                    map.erase(s[i]);
                    i++;
                }
                map[s[j]] = 1;
            }
        }
        return res;
    }
};

