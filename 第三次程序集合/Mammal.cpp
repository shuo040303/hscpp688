#include<iostream>
using namespace std;
class Mammal{
public:
    virtual void speak(){
        cout<<"哺乳动物在叫"<<endl;
    }
};
class Dog:public Mammal{
public:
    void speak(){
        cout<<"狗在叫"<<endl;
    }
};
int main(){
    Dog a;
    a.speak();
    return 0;
}