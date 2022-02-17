#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses,v);//构建临接表（用vector储存临接点，方便访问）

        for (int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//存的是出边
        }
        //将入度为0的顶点入队
        queue<int> myqueue;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                myqueue.push(i);
        }
        int cnt = 0;
        while (!myqueue.empty())
        {
            int temp = myqueue.front();
            myqueue.pop();
            cnt++;
            //更新：
            for (int i = 0; i < graph[temp].size(); i++)
            {
                indegree[graph[temp][i]]--;
                if (indegree[graph[temp][i]] == 0)//放在这里做！只判断邻接点。
                    myqueue.push(graph[temp][i]);
            }
        }
        return cnt == numCourses;

    }
};

