#include <iostream>
#include <algorithm>
#include<map>
#include<cstring>
using namespace std;


struct student{
    int grade;
    char name[101]{};
    int age;
    //student (int Grade,char Name [],int Age): grade(Grade), age(Age){strcpy(name,Name)};
    student(){};//无参的构造函数
    student(int Grade , const char Name[], int Age){//有参的构造函数
        this->grade=Grade;
        strcpy(this->name, Name);
        this->age=Age;
    }
};




int main(){
    //无构造函数时初始化
    student stu1={100,"lucy",16};
    cout<<stu1.grade<<" "<<stu1.name<<" "<<stu1.age<<" "<<endl;

    //有构造函数初始化：
    student stu2(98,"frank",15);
    cout<<stu2.grade<<" "<<stu2.name<<" "<<stu2.age<<" "<<endl;

    //结构体数组赋初值
    int n=2;
    student people[n];
    for (int i = 0; i <n ; ++i) {
        scanf("%d%s%d",&people[i].grade,people[i].name,&people[i].age);//scanf不要留空格
    }
    for (int i = 0; i < n;i++){
        cout<<people[i].grade<<" "<<people[i].name<<" "<<people[i].age<<" "<<endl;
    }
    return 0;
}
