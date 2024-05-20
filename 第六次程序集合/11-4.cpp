#include<iostream>
#include<fstream>
using namespace std;
 
int main()
{
    char a[100];
    ifstream file2("test1.txt");
    if(!file2)
    {
        cout<<"fail to open";
        return 1;
    }
    file2.getline(a,100);
    cout<<a;
    file2.close();
    return 0;
} 