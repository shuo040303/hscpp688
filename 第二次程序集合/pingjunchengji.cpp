#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define N 8
int main(){
    int i=0;
    int num=0;
    int a[N];
    for(i;i<N;i++){  //输入学生成绩
        cin>>a[i];
        num+=a[i];
    }
    cout<<"平均成绩为："<<num/N<<endl;//输出平均成绩
}