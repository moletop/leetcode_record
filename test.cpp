#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;
int main() {
    vector<int>arr ={2,3,4,5,6,7,9,8,};

    map<int, int> map;
    for (int i = 0; i < arr.size(); ++i) {
        map[arr[i]]=i;
    }
    for(auto iter=map.begin(); iter!=map.end();iter++){
        cout<<iter->first<<" "<<iter->second<<endl;
    }

    return 0;
}