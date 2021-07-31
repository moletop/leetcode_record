
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int result = 1;//默认右边最后一个点必取
        int cur = 0;//记录当前点的趋势
        int pre = 0;//记录之前点的趋势
        for (int i = 0; i < nums.size() - 1; ++i) {
            cur = nums[i + 1] - nums[i];
            if (pre <= 0 && cur > 0 || pre >= 0 && cur < 0) {//转折点记下，有两种情况
                result++;
                pre = cur;
            }
        }
        return result;

    }
};


int main() {
    vector<int> num;
    int result;
    Solution solution;
    int tem;
    while (cin >> tem) {
        num.push_back(tem);
        if (getchar() == '\n')
            break;
    }
    result = solution.wiggleMaxLength(num);
    cout << result << endl;


    return 0;
}