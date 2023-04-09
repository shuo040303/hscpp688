#include<iostream>
using namespace std;
void exchange(int *p1,int *p2,int r,int c){
	int i,j;             
	for(i=0;i<r;i++){
		cout<<"请输入矩阵的第"<<i<<"行元素:"<<endl;  //输入矩阵
		for(j=0;j<c;j++)			
			cin>>p1[i*c+j];
		}
	for(i=0;i<c;i++)
		for(j=0;j<r;j++)
			p2[i*r+j]=p1[i+c*j];               //矩阵转置;这里的i j分别代表转置后的行列
	for(i=0;i<c;i++){          //输出矩阵
		for(j=0;j<r;j++)
			cout<<p2[i*r+j]<<' ';
			cout<<endl;
		}
}
int main(){
	int r,c;
	cout<<"请输入矩阵行数:"<<endl;
	cin>>r;
	cout<<"请输入矩阵列数:"<<endl;
	cin>>c;
	int *p3=new int[r*c];
	int *p4=new int[r*c];
	exchange(p3,p4,r,c);
	return 0;
}
