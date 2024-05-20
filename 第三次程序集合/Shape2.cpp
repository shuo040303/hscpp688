#include<iostream>
#define PI 3.14
using namespace std;
class Shape{
public:
    virtual int getArea()=0;
    virtual int getPerim()=0;
    int getVertexCount(){
        return 4;
    }
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
class Square:public Rectangle{
public:
    int c;
};
int main(){
    Rectangle a(10,20);
    Circle b(5);
    cout<<a.getArea()<<" "<<a.getPerim()<<endl;
    cout<<b.getArea()<<" "<<b.getPerim()<<endl;
    Circle *m=new Circle;
    Shape *k=dynamic_cast<Shape*>(m);
    cout<<k->getVertexCount();
    return 0;

}