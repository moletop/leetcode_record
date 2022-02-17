#include<bits/stdc++.h>
using namespace std;

//这个题在II的基础上省略res即可

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //vector<int> res = {};
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;//入度
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//邻接表
        }

        queue<int> que;
        for(int i = 0; i < numCourses; i++) if(indegree[i] == 0) que.push(i);//入度为0的入队列

        int cnt = 0;
        while(!que.empty()){
            int tem = que.front();
            //res.push_back(tem);
            cnt++;
            que.pop();

            for(int i = 0; i < graph[tem].size(); i++){
                indegree[graph[tem][i]]--;
                if(indegree[graph[tem][i]] == 0) que.push(graph[tem][i]);
            }
        }
        if(cnt == numCourses) return true;//全部出队列
        else return false;
    }
};