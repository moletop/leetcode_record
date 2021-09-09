
#include<bits/stdc++.h>
using namespace std;

//维护两个队列（直接用vector a ，b）
//一个是单调队列a, 用来求最大值
//一个是普通队列b, 用来记录原始数组，支持pop_front()
class MaxQueue {
public:
    vector<int>a;//维持单调队列
    vector<int>b;//记录原始数组

    MaxQueue() {
        a.clear();
        b.clear();
    }

    int max_value() {
        if(a.empty()) return -1;
        return a[0];

    }

    void push_back(int value) {//实现单调队列
        while(!a.empty()&&value>a.back()) a.pop_back();
        a.push_back(value);
        b.push_back(value);
    }

    int pop_front() {//
        if(a.empty()) return -1;
        int res= b[0];
        if(b[0]==a[0]) a.erase(a.begin());
        b.erase(b.begin());
        return res;

    }
};