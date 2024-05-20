#include<iostream>
#include<string>
using namespace std;
class BaseClass{
public:
    virtual void fn1(){}
    void fn2(){}
    int a=10;
};
class DerivedClass:public BaseClass{
public:
    void fn1(){
        cout<<a<<endl;
    }
    void fn2(){
        cout<<a+a<<endl;
    }
};
int main(){
    DerivedClass b;
    BaseClass *p=&b;
    cout<<p->a<<endl;
    p->fn1();
    p->fn2();
    DerivedClass *a=&b;
    cout<<a->a<<endl;
    a->fn1();
    a->fn2();
    return 0;
}