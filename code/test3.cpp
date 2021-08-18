#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct student{
    int grade;
    char name[20];
    int age;
};

bool cmp(student a,student b){
    int t = strcmp(a.name,b.name);
    if(a.grade != b.grade)
        return a.grade > b.grade;
    else if(t != 0)
        return t > 0;
    else
        return a.age > b.age;
}

int main(){
    student stu[5]={{98,"frank",15},{96,"frtgg",15},{78,"asfffas",13},{87,"sifhsh",17},{87,"sifhsh",16}};
    sort(stu,stu+5,cmp);
    for (int i = 0; i < 5;i++){
        cout<<stu[i].grade<<" "<<stu[i].name<<" "<<stu[i].age<<" "<<endl;
   }
    return 0;

}