#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twenty=0;
        for (int i = 0; i <bills.size() ; ++i) {
            if(bills[i]==5){
                five++;
            }
            if(bills[i]==10){
                if(five==0) return false;
                else{five--;ten++;}
            }
            if(bills[i]==20){
                twenty++;
                if(ten>0&&five>0){ten--;five--;}
                else if(five>=3) five-=3;
                else return false;
            }
        }
        return true;
    }
};


int main(){
    vector<int> bills;
    bool result;
    Solution solution;
    int tem=0;
    while(cin>>tem){
        bills.push_back(tem);
        if(getchar()=='\n')
            break;
    }

    result=solution.lemonadeChange(bills);
    cout<<result<<endl;
    return 0;
}