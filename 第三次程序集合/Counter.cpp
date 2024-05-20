#include<iostream>
using namespace std;
class Counter{
public:
    int a;
    Counter(){}
    Counter(int a){
        this->a=a;
    }
    Counter operator+(const Counter& p){
        Counter b;
        b.a=this->a+p.a;
        return b;
    }
};
int main(){
    Counter b1(10);
    Counter b2(20);
    Counter b3=b1+b2;
    cout<<b3.a<<endl;
    return 0;
}