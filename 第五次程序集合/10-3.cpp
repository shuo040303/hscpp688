#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s;
    bool flag = true;
    int x;
    while(flag)
    {
        cout<<"Please enter a integer: (0 exit)";
        cin>>x;
        if(x)
        {
            s.push_back(x);
            cout<<s.capacity()<<endl;//容器的动态存储容量
        }
        else
            flag = false;
    }
    return 0;
}