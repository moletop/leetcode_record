#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int>st_in,st_out;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result;
        if(st_out.empty()){
            while(!st_in.empty()){
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        result =st_out.top();
        st_out.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        int res =this->pop();
        st_out.push(res);
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st_in.empty()&st_out.empty();
    }
};



int main(){
    MyQueue myqueue;
    myqueue.push(1);
    myqueue.push(2);
    cout<< myqueue.peek()<< endl;
    cout<< myqueue.pop()<< endl;
    cout << myqueue.empty()<<endl;
return 0;

}
