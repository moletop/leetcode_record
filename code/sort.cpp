#include <iostream>
#include <vector>

using namespace std;

//判断两个数组那个字典序排列在前
bool dictOrder(vector<int> cur, vector<int> competitor){
    for(int i = 0; i < competitor.size(); i++){
        if(cur[i] <= competitor[i]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

//动态规划，记录i每向前移一位时，搜索以input[i]结尾的最长递增子序列，并将这个子序列存储在“store”数组中。
vector<int> fun(vector<int>& input){
    vector<vector<int>> store(input.size());
    store[0] = {input[0]};
    for(int i = 1; i < input.size(); i++){
        int longest = 0;
        for(int j = 0; j < i; j++){
            if(*store[j].rbegin() < input[i]){
                if(store[j].size() + 1 > longest){
                    store[i] = store[j];
                    store[i].emplace_back(input[i]);
                    longest = store[j].size();
                }
                else if(store[j].size() + 1 == longest){
                    if(dictOrder(store[i], store[j]) == false){
                        store[i] = store[j];
                        store[i].emplace_back(input[i]);
                        longest = store[j].size();
                    }
                }
            }
        }
        if(store[i].size() == 0){
            store[i].emplace_back(input[i]);
        }
    }

//找出所有以input[i]结尾的递增子序列中最长的
    vector<int> ans;
    for(auto &vec : store){
        if(ans.size() < vec.size()){
            ans = vec;
        }
        else if(ans.size() == vec.size() && vec.size() && ans.size()){
            if(dictOrder(ans, vec) == false){
                ans = vec;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    vector<int> ans = fun(input);
    for(int num : ans){
        cout << num << ' ';
    }

    return 0;
}
