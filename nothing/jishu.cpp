#include<iostream>
using namespace std;
int main(){
    int low,high;
    cin>>low>>high;
    int i=low,j;
    int num=high-low+1;
    for(i;i<=high;i++){
        for(j=2;j<i;j++){
            if(i%j==0)
            {num--;
            break;}
        }
    }
    cout<<num<<endl;
}