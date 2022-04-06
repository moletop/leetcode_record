#include<bits/stdc++.h>
using namespace std;
//https://blog.csdn.net/weixin_42437295/article/details/90771962
void quick_sort(vector<int> &nums,int L,int R) {
    if(L >= R) return;
    int left = L; int right = R;
    int ans = nums[L];
    while(L < R){
        while(L < R && nums[R] >= ans) R--;
        while(L < R && nums[L] <= ans) L++;
        if(L < R) swap(nums[L], nums[R]);
    }
    swap(nums[L], nums[left]);
    quick_sort(nums, left, L - 1);
    quick_sort(nums, L + 1, right);
}

int main(){
    vector<int> res = {1,3,5,6,7,4,6,3};
    quick_sort(res, 0, res.size() - 1);
    for(auto i : res){
        printf("%d ",i);
    }
    return 0;
}