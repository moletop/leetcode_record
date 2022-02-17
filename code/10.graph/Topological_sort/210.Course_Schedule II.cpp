#include<bits/stdc++.h>
using namespace std;

/*
掌握图节点的出度和入度概念

以及图的邻接表定义

本题利用一个队列 实现拓扑排序

*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res = {};
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
            res.push_back(tem); cnt++;
            que.pop();

            for(int i = 0; i < graph[tem].size(); i++){
                indegree[graph[tem][i]]--;
                if(indegree[graph[tem][i]] == 0) que.push(graph[tem][i]);
            }
        }
        if(cnt == numCourses) return res;//全部出队列
        else return {};
    }
};


