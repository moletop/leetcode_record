#include<bits/stdc++.h>
using namespace std;
typedef pair<char,int> PAIR;
char* fun(char* s,int n){
    char* h=s; char* res=new char[n]{'0'};
    map<char,int> map; vector<pair<char,int>> vec;

    for(int i = 0; i < n ;i ++){
        map[h[i]]++;
    }

    for (auto i = map.begin(); i != map.end(); ++i) {
        vec.emplace_back(i->first,i->second);
    }
    sort(vec.begin(),vec.end(),[](PAIR a,PAIR b){
        if(a.second>b.first) return a<b;
        else return a>b;
    });

    for(int i = 0; i <vec.size() ; ++i) {
        for (int j = 0; j < n; ++j) {
            if(j==0){
                if(res[j]=='0') res[j] = vec[i].first;
                else continue;
            }else{
                if(res[j-1]!=vec[i].first&&res[j]=='0') res[j]=vec[i].first;
                else continue;
            }
        }
    }
}




int main(){
    char* arr=new char[]();





    return 0;
}
// Created by winter on 2021/10/16.
//

