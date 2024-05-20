#include<iostream>
#include<string>
using namespace std;
class BaseClass{
public:
    virtual ~BaseClass(){
        cout<<"父类析构函数调用"<<endl;
    }
};
class DerivedClass:public BaseClass{
public:
   int a;
};
int main(){
    BaseClass *p=new DerivedClass;
    delete p;
    return 0;
}