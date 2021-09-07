#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> output;
    vector<int> printNumbers(int n) {
        // 以下注释的前提：假设 n = 3
        if(n <= 0) return vector<int>(0);
        string s(n, '0'); // s最大会等于999，即s的长度为n
        while(!overflow(s)) inputNumbers(s);
        return output;
    }

    bool overflow(string& s)
    {
        // 本函数用于模拟数字的累加过程，并判断是否越界（即 999 + 1 = 1000，就是越界情况）
        bool isOverFlow = false;
        int carry = 0; // carry表示进位
        for(int i=s.length()-1; i>=0; --i)
        {
            int current = s[i] - '0' + carry; // current表示当前这次的操作
            if(i == s.length() - 1) current ++; // 如果i此时在个位，current执行 +1 操作
            if(current >= 10)
            {
                // 假如i已经在最大的那一位了，而current++之后>=10，说明循环到头了，即999 + 1 = 1000
                if(i == 0) isOverFlow = true;
                else
                {
                    // 只是普通进位，比如current从9变成10
                    carry = 1;
                    s[i] = current - 10 + '0';
                }
            }
            else
            {
                // 如果没有进位，更新s[i]的值，然后直接跳出循环，这样就可以回去执行inputNumbers函数了，即往output里添加元素
                s[i] = current + '0';
                break;
            }
        }
        return isOverFlow;
    }


    void inputNumbers(string s)
    {
        // 本函数用于循环往output中添加符合传统阅读习惯的元素。比如001，我们会添加1而不是001。
        bool isUnwantedZero = true; // 判断是否是不需要添加的0，比如001前面的两个0
        string temp = "";
        for(int i=0; i<s.length(); ++i)
        {
            if(isUnwantedZero && s[i] != '0') isUnwantedZero = false;
            if(!isUnwantedZero) temp += s[i];
        }
        output.push_back(stoi(temp));
    }
};
