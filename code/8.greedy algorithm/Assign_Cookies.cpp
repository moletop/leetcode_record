#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        int result=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());//排序
        int pr = s.size() - 1;.//饼从大的开始分配
        for (int i = g.size()-1; i >= 0; --i) {
            if (pr >= 0&&s[pr] >= g[i] ) {
                pr--;
                result++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> g;
    vector<int> s;
    Solution solution;
    int result;
    int tem = 0;

    while (cin>>tem) {//当输入符合，则一直循环
        g.push_back(tem);
        if (getchar() == '\n')//遇到回车，跳出循环
            break;
    }

    while (cin>>tem) {

        s.push_back(tem);
        if (getchar() == '\n')
            break;
    }

    result = solution.findContentChildren(g, s);
    cout << result << endl;
    return 0;
}



