/*
创建一个矩形类，矩形的边平行于坐标轴。矩形的属性用其左下角坐标、长度和宽度描述。
(1) 从键盘输入两个矩形参数（注意输入提示信息），创建两个矩形对象，
     判断两个矩形是否相交？求出相交部分的面积。
(2) 从键盘再输入或随机产生3个矩形对象，对输入的所有5个矩形按面积由小到大排序，
     然后依次显示各个矩形的左下角坐标、长、宽、面积。
*/
#include<string>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class point{
public:
     int x,y;
     point(){}
     point(int x,int y){
          this->x=x;
          this->y=y;
     }
};
class rec:public point{
public:
     int longth;
     int width;
     rec(){}
     rec(int longth,int width){
          this->longth=longth;
          this->width=width;
     }
     
};
point test01(int m,int n){
     point p(m,n);
     return p;
}
rec test02(int a,int b){
     rec r(a,b);
     return r;
}
int change(int a,int b){
     if(a-b<0){
          return b-a;
     }
     return a-b;
}
int ismin(int a,int b){
     if(a>b){
          return b;
     }
     return a;
}
void istouch(point &p1,point &p2,rec &r1,rec &r2){
     if(change(p1.x,p2.x)<=r1.longth||change(p1.y,p2.y)<=r1.width){
          cout<<"两矩形相交！"<<endl;
     }
     else{
          cout<<"不相交"<<endl;
     }
}
int getsize(point &p1,point &p2,rec &r1,rec &r2){
     return (r1.longth-change(p1.x,p2.x))*(r1.width-change(p1.y,p2.y));
}
void print1(rec &r1){
     cout<<"矩形的左下角下标为："<<r1.x<<","<<r1.y<<"  ";
     cout<<"矩形的长为："<<r1.longth<<"  ";
     cout<<"矩形的宽为："<<r1.width<<"  ";
     cout<<"矩形的面积为："<<r1.longth*r1.width;
     cout<<endl;
}
void print2(rec &r1){
     cout<<"矩形的长为："<<r1.longth<<"  ";
     cout<<"矩形的宽为："<<r1.width<<"  ";
     cout<<"矩形的面积为："<<r1.longth*r1.width;
     cout<<endl;
}
int main(){
     point p1=test01(3,2);
     point p2=test01(4,5);
     int longth1,width1;
     cout<<"请输入矩形1的长和宽：";
     cin>>longth1>>width1;
     rec r1=test02(longth1,width1);
     int longth2,width2;
     cout<<"请输入矩形2的长和宽：";
     cin>>longth2>>width2;
     rec r2=test02(longth2,width2);
     istouch(p1,p2,r1,r2);
     int s=getsize(p1,p2,r1,r2);
     cout<<"相交的面积为："<<s;
     int longth3,longth4,longth5;
     int width3,width4,width5;
     cout<<"请输入矩形3的长和宽：";
     cin>>longth3>>width3;
     cout<<"请输入矩形4的长和宽：";
     cin>>longth4>>width4;
     cout<<"请输入矩形5的长和宽：";
     cin>>longth5>>width5;
     rec r3=test02(longth3,width3);
     rec r4=test02(longth4,width4);
     rec r5=test02(longth5,width5);
     r3.x=4;
     r3.y=5;
     r4.x=7;
     r4.y=9;
     r5.x=3;
     r5.y=6;

     int sz[5];
     sz[0]=r1.longth*r1.width;
     sz[1]=r2.longth*r2.width;
     sz[2]=r3.longth*r3.width;
     sz[3]=r4.longth*r4.width;
     sz[4]=r5.longth*r5.width;
     int i,j,t;
     int a[5];
     for(i=0;i<5;i++){
          a[i]=sz[i];
     }
     for(i=0;i<4;i++)

    {

        for(j=i+1;j<5;j++)

        {

           if(a[i]>a[j])

           {

               t=a[i];

               a[i]=a[j];

               a[j]=t;

           }

        }

    }
     for(i=0;i<5;i++){
     if(a[i]==sz[0]){
                    cout<<"矩形的左下角下标为："<<p1.x<<","<<p1.y<<"  ";
                    print2(r1);
                   
               }
               if(a[i]==sz[1]){
                    cout<<"矩形的左下角下标为："<<p2.x<<","<<p2.y<<"  ";
                    print2(r2);
                    
               }
               if(a[i]==sz[2]){
                    print1(r3);
                    
               }
               if(a[i]==sz[3]){
                    print1(r4);
                    
               }
               if(a[i]==sz[4]){
                    print1(r5);
                   
               }
    }

     return 0;
}

