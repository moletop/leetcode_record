#include<bits/stdc++.h>
using namespace std;


//如果两个词属于同一个异位词，那他们排好序后的字符串应该是一样的，以排好的字符串为哈希键构造哈希表，将映射符合的字符串添加到对应哈希值中。


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            map[key].push_back(strs[i]);
        }

        for (auto i = map.begin(); i != map.end(); i++) {
            res.push_back(i->second);
        }
        return res;

    }
};

