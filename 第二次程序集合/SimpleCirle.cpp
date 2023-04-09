#include<iostream>
using namespace std;
#define PI 3.14
class SimpleCircle{
    private:
        int *itsRadius=new int(0);
    public:
        SimpleCircle(){}
        SimpleCircle(int Radius){
            *itsRadius=Radius;
        }
        void CircleC(){
            cout<<"圆的周长为："<<2*PI*(*itsRadius)<<endl;
        }
        void CircleS(){
            cout<<"圆的面积为："<<PI*(*itsRadius)*(*itsRadius)<<endl;
        }
        int getRadius(){
            return *itsRadius;
        }
        ~SimpleCircle(){}
};
int main(){
    SimpleCircle c(10);
    cout<<"圆的半径为："<<c.getRadius()<<endl;
    c.CircleC();
    c.CircleS();
    return 0;
}