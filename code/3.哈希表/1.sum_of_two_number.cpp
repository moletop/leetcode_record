#include <iostream>
#include<algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <nums.size() ; ++i) {
            cout<<nums[i]<<endl;
        }

        int left =0;
        int right = nums.size()-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum ==target){
                result.push_back(left);
                result.push_back(right);
                left++;
                right--;
            }
            else if(sum>target){
                right--;
            }
            else{
                left ++;
            }
        }
        return result;
    }
};

int main(){
    Solution p;
    int n;
    scanf("%d",&n);
    vector<int>obj;int targrt;
    cin>>targrt;
    for(int i=0;i<n;i++)
    {   int num=0;
        scanf("%d",&num);
        obj.push_back(num);
    }

   vector<int> obj2=p.twoSum(obj,targrt);
    for (int i = 0; i <obj2.size() ; ++i) {
        cout<<obj2[i]<<endl;
    }
    return 0;
}


