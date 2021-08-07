#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int candy(vector<int>& ratings){
        int result=0;
        int n=ratings.size();
        vector<int> left(n);//从左边往右遍历 ，给的糖果的数组

        for (int i = 0; i <n ; ++i) {
            if(i>0&&ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;//如果当前的等级大于前一个，则给糖果数目比前面的大1
            }
            else left[i]=1;//否则直接给1
        }


        for(int i=n-1;i>=0;i--){// 从右向左遍历
            int right=0;
            if(i<n-1&&ratings[i]>ratings[i+1]) {//如果当前的等级大于后一个，则用right记录下(后一个+1)的糖果数目
                right = left[i + 1] + 1;
            }
            else right=1;//否则等于1
            left[i]=max(left[i],right);
        }

        for(int i=0 ;i<left.size();i++){
            result+=left[i];
        }
        return result;
    }
};

int main(){
    vector<int >ratings;
    Solution solution;
    int tem=0;
    while(cin>>tem){
        ratings.push_back(tem);
        if(getchar()=='\n')
            break;
    }
    int result =solution.candy(ratings);
    cout<<result<<endl;
    return 0;
}


