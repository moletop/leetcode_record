#include<bits/stdc++.h>
using namespace std;

//实现一个能得到栈中最小元素的栈
//我的代码
class MinStack {
public:
    stack<int> ans;//
    map<int ,int> map;//核心利用map的自动根据key从大到小排序
    int min_element;

    /** initialize your data structure here. */
    MinStack() {
        while(!ans.empty()) ans.pop();
        map.clear();
        min_element = INT_MAX;
    }

    void push(int val) {
        if(val < min_element) min_element = val;
        ans.push(val);
        map[val]++;
    }

    void pop() {
        map[ans.top()]--;
        if(map[ans.top()] == 0) map.erase(map.find(ans.top()));
        ans.pop();
        if(!map.empty()) min_element = map.begin()->first;
        return;
    }

    int top() {
        return ans.top();
    }

    int getMin() {
        return map.begin() -> first;
    }
};

//大佬的代码
/*
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = [math.inf]

    def push(self, x: int) -> None:
        self.stack.append(x)
        self.min_stack.append(min(x, self.min_stack[-1]))

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]
*/




