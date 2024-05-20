#include<string>
#include<iostream>
using namespace std;
class Point{
public:
    Point(){
        num=0;
    }
    Point& operator++(){
        num++;
        return *this;
    }
    Point& operator--(){
        num--;
        return *this;
    }
    Point operator++(int){
        Point temp=*this;
        num++;
        return temp;
    }
    Point operator--(int){
        Point temp=*this;
        num--;
        return temp;
    }
    int getnum(){
        return num;
    }
public:
    int num;
};
void test01(){
    Point p;
    cout<<(++p).getnum()<<endl;
    cout<<p.getnum()<<endl;
}
void test02(){
    Point p;
    cout<<(p++).getnum()<<endl;
    cout<<p.getnum()<<endl;
}
void test03(){
    Point p;
    cout<<(--p).getnum()<<endl;
    cout<<p.getnum()<<endl;
}
void test04(){
    Point p;
    cout<<(p--).getnum()<<endl;
    cout<<p.getnum()<<endl;
}
int main(){
    test02();
    system("pause");
    return 0;
}