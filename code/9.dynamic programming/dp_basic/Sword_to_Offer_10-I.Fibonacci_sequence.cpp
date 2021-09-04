#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        vector<unsigned long long >arr(n+1,0);
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<=n;i++){
            arr[i]=(arr[i-1]%1000000007+arr[i-2]%1000000007)%1000000007;//注意这里每次前两个互相加都要取模
        }
        return arr[n]%1000000007;
    }
};

