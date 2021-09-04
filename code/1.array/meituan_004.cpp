#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void one(vector<int>&a,vector<int>&b,int k,int x,int y){
        int i=x-1;
        int j=y-1;
        for(int l=k;l>0&&j<b.size()&&i<a.size();l--){
            b[j++]=a[i++];//
        }
        return;
    }
    void two(vector<int>b,int x){
        cout<<b[x-1]<<endl;//
        return;
    }


};
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n,-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int num;
    cin>>num;
    Solution s;
    while(num--){
        int tem=0;cin>>tem;
        if(tem==2) {
            int tem1=0;
            cin>>tem1;
            s.two(b,tem1);
        }//getchar()可以接收回车
        else{
            int o=0,p=0,q=0;
            cin>>o>>p>>q;
            s.one(a,b,o,p,q);
        }
    }
    return 0;
}

