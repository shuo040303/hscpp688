#include<iostream>
using namespace std;
class Point{
public:
    int x,y;
    friend Point operator+(const Point&a,const Point&b);
};
 Point operator+(const Point&a,const Point&b){
    Point t;
    t.x=a.x+b.x;
    t.y=a.y+b.y;
    return t;
}
int main(){
    Point a,b;
    a.x=10;
    b.x=15;
    a.y=11;
    b.y=19;
    Point c=a+b;
    cout<<c.x<<" "<<c.y<<endl;
    return 0;
}