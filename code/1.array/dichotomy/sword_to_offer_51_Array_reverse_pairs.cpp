#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int> data) {
        vector<int> tem(data.size());
        return Merge_sort(0 , data.size()-1 , data , tem);

    }
private:
    int Merge_sort(int l , int r, vector<int> &nums, vector<int>& tem){
        //终止
        if(l >= r) return 0;
        //划分 
        int m = l + (r - l) / 2;
        int res = Merge_sort(l , m , nums , tem) + Merge_sort( m + 1 , r , nums , tem);

        //合并
        for(int i = l ; i <= r; i++){//复制一份，后面好排序
            tem[i] = nums[i];
        }

        int p = l;//双指针
        int q = m + 1;

        for(int i = l ; i <= r ; i ++){
            if(p == m+1 ) {nums[i] = tem[q]; q++;}//拿右边第1种情况
            else if(q == r+1 ||tem[p] <= tem[q]) {nums[i] = tem[p]; p++;}//拿左边1、2种情况
            else {//拿右边第2种情况
                res += m - p + 1;
                nums[i] =tem[q];
                q ++;
            }
        }
        return res;
    }
};