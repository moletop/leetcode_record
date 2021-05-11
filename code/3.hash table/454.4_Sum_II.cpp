#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int > map;
        for (int i: nums1) {
            for(int j : nums2){
                map[i+j]++;
            }
        }
        int count = 0;
        for(int i : nums3){
            for(int j : nums4){
                int tem = -(i + j);
                if(map.find(tem) != map.end()){
                    count += map[tem];
                }
            }
        }
        return count;
    }
};



int main(){
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0, 2};


    Solution solution;
    int count = solution.fourSumCount(nums1,nums2,nums3,nums4);
    cout << count<< endl;

    return 0;
}