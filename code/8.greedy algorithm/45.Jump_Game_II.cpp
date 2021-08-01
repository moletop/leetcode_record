#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump1(vector<int> &nums) {//暴力
        vector<int> str;//开一个存放 达到每个点最少跳跃次数的 数组
        for (int i = 0; i < nums.size(); i++)
            str.push_back(1e9);//先都给最大
        str[0] = 0;//第一个给0
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= i + nums[i] && j < nums.size(); ++j) {
                if (str[i] + 1 < str[j]) {//如果当前记录值加1，比一步到达的点的记录值小，就更改他们的记录值
                    str[j] = str[i] + 1;
                }
            }
        }
        return str[nums.size() - 1];//返回最后一个元素的记录值
    }


int jump2(vector<int> &nums) {//贪心,从每次能跳到的最大范围里，挑一个使得下一次能跳到最大范围的点。
    int maxfar = 0;//遍历时实时更新的最远距离。
    int end = 0;//每次跳跃点可达的最远距离（遍历阈值）
    int step = 0;//记录步数

    for (int i = 0; i < nums.size()-1; ++i) {
        maxfar = max(maxfar, i+nums[i]);

        if (i == end) {//到达阈值后更新为新的阈值
            end = maxfar;
            step++;//跳跃次数加1
        }
    }
    return step;
}

};


int main() {
    Solution solution;
    vector<int> nums;
    int tem = 0;
    while (cin >> tem) {
        nums.push_back(tem);
        if (getchar() == '\n') break;
    }
    int result = solution.jump2(nums);
    cout << result << endl;
    return 0;
}