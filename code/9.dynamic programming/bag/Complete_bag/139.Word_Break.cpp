
#include<bit/std.c++>
using namespace std;

//完全背包

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, 0);//dp[i]:s[0:i]之间是不是可以被拆分为字典中的单词
        dp[0] =1;//空字符。满足递归需求，没有实际意义
        for(int i = 1; i <= n; i++ ){//遍历背包容量
            for(int j = 0; j < i; j++){//遍历能存的物品
                string tem = s.substr(j, i - j);//(i-1)-j+1
                //是否在备选物品（字典单词）中,qie前面的字典单词中的单词
                if(find(wordDict.begin(),wordDict.end(),tem) != wordDict.end() && dp[j] == 1) dp[i] = 1;
            }
        }
        return dp[n];
    }
};
