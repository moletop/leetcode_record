#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int totalFruit(vector<int>&fruits){
        int res = 0;
        int fir = 0;
        unordered_map<int,int> bucket;
        for (int sec = 0; sec <fruits.size() ; ++sec) {
            bucket[fruits[sec]]++;
            while(bucket.size()>2){
                bucket[fruits[fir]]--;
                if(bucket[fruits[fir]]==0) bucket.erase(fruits[fir]);
                fir++;
            }
            res= res > sec - fir +1 ? res : sec  - fir +1 ;
        }
        return res;
    }
};
