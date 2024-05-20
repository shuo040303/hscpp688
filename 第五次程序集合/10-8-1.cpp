#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    set<string> s1;
    multiset<string> s2;
    string word;
 
    //读入单词并统计其出现次数
    cout<<"Enter some words(Ctrl+Z to end):"<<endl;
    while(cin>>word)
    {
        s1.insert(word);
        s2.insert(word);
    }
    //输出结果
    cout<<"word\t\t"<<"times"<<endl;
    set<string>::iterator iter;
    for(iter=s1.begin(); iter!=s1.end(); ++iter)
    {
        cout<<(*iter)<<": "<<s2.count(*iter)<<endl;
    }
 
    return 0;
}