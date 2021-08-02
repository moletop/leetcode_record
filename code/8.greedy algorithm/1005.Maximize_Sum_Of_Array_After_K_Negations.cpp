#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        for(int i =0;i<k;i++){
            int tem=min_element(nums.begin(),nums.end())-nums.begin();//每次取最小的值取负值
            nums[tem]=-nums[tem];
        }
        int sum=0;
        for(auto i:nums)
            sum+=i;
        return sum;
    }
};


int main(){
    Solution solution;
    vector<int> nums;
    int k=0;
    int tem=0;
    cin>>k;
    //scanf("%d",&k);

    while(cin>>tem){
        nums.push_back(tem);
        if(getchar()=='\n')
        break;
    }
    int result =solution.largestSumAfterKNegations(nums,k);
    cout<<result<<endl;
    return 0;
}
