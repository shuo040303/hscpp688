#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    map<string , int> wordCount;
    string word;
 
    //读入单词并统计其出现次数
    cout<<"Enter some words(Ctrl+Z to end):"
        <<endl;
    while(cin>>word)
        ++wordCount[word];  //word的出现次数加1
 
    //输出结果
    cout<<"word\t\t"<<"times"<<endl;
    for(map<string, int>::iterator iter = wordCount.begin() ; iter != wordCount.end() ; ++iter)
        cout<<(*iter).first<<"\t\t"
            <<(*iter).second<<endl;
 
    return 0;
}