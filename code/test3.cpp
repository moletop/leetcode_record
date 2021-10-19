#include<bits/stdc++.h>
using namespace std;

class StockPrice {
public:
    int a[1000000000];

    StockPrice() {
    }

    void update(int timestamp, int price) {
        a[timestamp] = price;

    }

    int current() {
        for(int i = 1000000000-1; i>0; i--){
            if(a[i] != 0) return a[i];
        }
    }

    int maximum() {
        sort(a,a+1000000000-1);
        return a[1000000000-1];
    }

    int minimum() {
        int res=INT_MAX;
        for(int i = 0; i< 100; i ++){
            if(a[i] == 0) continue;
            if(a[i] < res) res = a[i];
        }
        return res;
}
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */