/*本体重点：
熟悉0-9 A-Z a-z 的ASCII码的分布，他们分别是不连续的。
开始序号 0是48 A是65 a是97。
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        string s;
        s.clear();
        cin>>s;
        int flag1=0,flag2=0,flag3=1;//三个信号
        if((s[0]<'a'||s[0]>'z')&&(s[0]<'A'||s[0]>'Z')) {cout<<"Wrong"<<endl;continue;}//第一层循环开始就把开头必须是字母的逻辑判断掉
        for(int j=0;j<s.size();j++){
            if(s[j]>='0'&&s[j]<='9') flag1++;//必须有数字
            else if(s[j]>='a'&&s[j]<='z'||s[j]>='A'&&s[j]<='Z') flag2++;//必须有字母
            else{flag3=0;break;}//必须全是数字或者字母，有一个不是就给失败信号，跳出循环
        }
        if(flag1>0&&flag2>0&&flag3>0) cout<<"Accept"<<endl;//三个信号满足
        else cout<<"Wrong"<<endl;

    }
    return 0;
}

