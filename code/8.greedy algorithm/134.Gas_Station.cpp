#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;//记录总rest
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
        return start;
    }
};

int main (){
    vector<int > gas;
    vector<int > cost;
    int result;
    Solution solution;
    int tem=0;
    while(cin>>tem){
        gas.push_back(tem);
        if(getchar()=='\n')
            break;
    }
    while(cin>>tem){
        cost.push_back(tem);
        if(getchar()=='\n')
            break;
    }
    result=solution.canCompleteCircuit(gas,cost);
    cout<<result<<endl;
    return 0;
}

