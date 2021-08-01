#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//贪心算法
//局部最优解：每次取最大跳跃步数（取最大覆盖范围），
//整体最优解：最后得到整体最大覆盖范围，看是否能到终点」。
//
//这道题还有点双指针的意思！

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover=0;//覆盖最远的数组下标
        for (int i = 0; i <=cover; ++i) {
            cover=max(cover,i+nums[i]);//更新覆盖最远的数组下标
            if(cover>=nums.size()-1)
                return true;
        }
        return false;
    }
};



int main (){
    Solution solution;
    vector<int >nums;
    int tem;
    while(cin>>tem){
        nums.push_back(tem);
        if(getchar()=='\n') break;
    }
    bool result =solution.canJump(nums);
    cout<<result<<endl;

    return 0;
}