#include<iostream>
using namespace std;
void fn1(){
    static int n=0;
    n++;
    cout<<"n的值为："<<n<<endl;
}
int main(){
    int i=10;
    while(i){
        fn1();
        i--;
    }
}