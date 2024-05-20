#include<iostream>
#define PI 3.14
using namespace std;
class Shape{
public:
    virtual int getArea()=0;
    virtual int getPerim()=0;
};
class Rectangle:public Shape{
public:
    Rectangle(){}
    Rectangle(int a,int b){
        this->a=a;
        this->b=b;
    }
    virtual int getArea(){
        return a*b;
    };
    virtual int getPerim(){
        return 2*a+2*b;
    };
    int a,b;
};
class Circle:public Shape{
public:
    Circle(){}
    Circle(int r){
        this->r=r;
    }
    virtual int getArea(){
        return PI*r*r;
    };
    virtual int getPerim(){
        return 2*PI*r;
            };
    int r;
};
int main(){
    Rectangle a(10,20);
    Circle b(5);
    cout<<a.getArea()<<" "<<a.getPerim()<<endl;
    cout<<b.getArea()<<" "<<b.getPerim()<<endl;
    return 0;

}