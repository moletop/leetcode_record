#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*假如第0天买入，第3天卖出，那么利润为：prices[3] - prices[0]。

相当于(prices[3] - prices[2]) + (prices[2] - prices[1]) + (prices[1] - prices[0])。

「此时就是把利润分解为每天为单位的维度，而不是从0天到第3天整体去考虑！
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        int tem=0;
        for (int i = 0; i <prices.size()-1 ; ++i) {
            tem=prices[i+1]-prices[i];//
            if(tem>0)
                result+=tem;
        }
        return result;
    }
};

int main (){
    vector<int> prices;
    int tem=0;
    Solution solution;
    while(cin>>tem){
        prices.push_back(tem);
        if(getchar()=='\n')
            break;
    }
    int result=solution.maxProfit(prices);
    cout<<result<<endl;
    return 0;
}