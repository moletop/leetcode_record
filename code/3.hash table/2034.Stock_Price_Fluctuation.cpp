#include<bits/stdc++.h>
using namespace std;
//给一对多实时排序提供了思路。很nice!

class StockPrice {
    map<int,int> m;//时间，价格
    set<pair<int,int>> s;//价格，时间：方便实现寻找最大最小值
public:
    StockPrice() {
        m.clear();
        s.clear();
    }

    void update(int timestamp, int price) {
        if(m.count(timestamp))s.erase(make_pair(m[timestamp],timestamp));//pair 保证唯一对，不会被后面的相同的价格覆盖时间戳（因为一个价格可以对应多个时间戳）
        m[timestamp]=price;
        s.insert(make_pair(m[timestamp],timestamp));
    }

    int current() {
        return m.rbegin()->second;
    }

    int maximum() {
        return s.rbegin()->first;
    }

    int minimum() {
        return s.begin()->first;
    }
};

