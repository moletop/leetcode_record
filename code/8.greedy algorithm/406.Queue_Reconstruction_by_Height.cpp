#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
        if(a[0]!=b[0]) return a[0]>b[0];
        else  return a[1]<b[1];
    }

    static vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>que;
        for(auto i : people){
            int position=i[1];
            que.insert(que.begin()+position,i);
        }
        return que;
    }
};

