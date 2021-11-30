#include <iostream>
#include <vector>
#include <algorithm>
#include<string>


using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points){
        if(points.size()==1) return 1;

        sort(points.begin(),points.end());

        int flag=1;
        for (int i = 1; i < points.size(); ++i) {
            if(points[i][0]>points[i-1][1]) flag++;

            else{
                points[i][1]=min(points[i-1][1],points[i][1]);
            }
        }
        return flag;
    }
};

