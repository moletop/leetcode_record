#include<bits/stdc++.h>
using namespace std;

typedef pair<string, int> PAIR;

bool cmp_by_value(const PAIR& l, const PAIR& r) {
    return l.second < r.second;
}
int main() {
    map<string, int> name_score_map;
    name_score_map["LiMin"] = 90;
    name_score_map["ZiLinMi"] = 79;
    name_score_map["BoB"] = 92;
    name_score_map.insert(make_pair("BoB",99));//不会插入或者更新
    name_score_map.insert(make_pair("Albert",86));
    //把map中元素转存到vector中,以pair的形式
    vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());
    sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);
    auto iter = name_score_map.find("BoB");//找到要删除
    if(iter!=name_score_map.end()) name_score_map.erase(iter);
    for(auto iter : name_score_map) {//这里的ater不是迭代器，是指代元素，要注意
        cout << iter.first << endl;//注意:pair不能以元素遍历形式取出，只能以.first或者.second。(map迭代器用->,不用.)
        // for (auto iter=name_score_map.begin();iter!=name_score_map.end();iter++) {
        //     cout << iter->second<< endl;
    }

    return 0;
}
//技巧:也可以把key和value颠倒组成pair，然后存进vector，这样不用写cmp