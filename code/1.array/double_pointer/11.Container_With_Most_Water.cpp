#include<bits/stdc++.h>
using namespace std;
//双指针和贪心
/*
贪心体现在： 每次从更小那边挡板往里移动
原因：每次移动 j-i必然减小, 如果从大挡板往里移动，新的min(height[i] , height[j])肯定不大于之前更小的那块挡板，所以装的水肯定比之前少，所以要从小挡板往里移动。
这样j-i 变小了，但是可能找到更大的min(height[i] , height[j]。

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int i = 0;
        int j = n - 1;
        for(;i < j ;){
            res = max(res , min(height[i] , height[j]) * (j - i));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
};
