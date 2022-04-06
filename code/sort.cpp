#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    string multiply(string nums1, string nums2){
        int m = nums1.size();
        int n = nums2.size();


        vector<int> res(m + n , 0);
        for(int i = m - 1; i >= 0; i --){
            for(int j = n -1; j >= 0; j --){
                int sum = (nums1[i] - '0') * (nums2[j] - '0');
                int high = i + j; int low = i + j + 1;
                sum += res[low];

                res[low] = sum % 10;
                res[high] += sum / 10;


            }
        }

        string s = "";
        for(int i = 0; i < res.size(); i ++){
            if(!(s.size() == 0 && s[i] == 0))
                s += to_string(res[i]);
        }
        return s;
    }
};
int main(){
    Solution solution;
    string s1 = "12";
    string s2 = "12";
    string res = solution.multiply(s1, s2);
    cout << res;



    return 0;
}