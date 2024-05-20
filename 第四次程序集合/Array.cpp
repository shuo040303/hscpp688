#include<iostream>
#include<iomanip>
#include"Array.h"
using namespace std;
 
int main()
{
    int n;
    double averscore, totalscore = 0;
    cout << "请输入学生人数：";
    cin >> n;
    Array<float> Score(n);
    for (int i = 0; i < n; i++)
    {
    	cout<<"请输入这"<<n<<"个学生在课程A中的考试成绩：";
        cin >> Score[i];
        totalscore += Score[i];
    }
    averscore = totalscore / n;
    cout << "平均成绩为：" << averscore;
    return 0;
}