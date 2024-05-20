//此系统为一个火车票务管理系统
#include<stdio.h>
#include<stdlib.h>
#include"worker.cpp"//工作人员的功能函数
#include"passenger.cpp"//乘客的功能函数
//设置身份选择界面
void option(){
    printf("*************************************************\n");
    printf("****请选择您的身份:A.工作人员 B.乘客 C.Exit******\n");
    printf("*************************************************\n");
    char op=getchar();//输入身份选择的情况
    getchar();
    static int error_count = 0; // 增加错误计数器
    if(op=='A'){
        printf("欢迎使用本系统，尊敬的工作人员！\n");
        worker();
    }
    else if(op=='B'){
        printf("欢迎使用本系统，尊敬的乘客！\n");
        passenger();
    }
    else if(op=='C'){}
    else{
        printf("您的输入有误，请重新选择！\n");
        error_count++; // 增加错误计数器
        if (error_count >= 3) { // 如果连续多次错误，提示重新登录
            printf("您的输入错误次数过多，请重新登录！\n");
            return;
        }
        option();
    }
}


int main(){
    //界面设置
    option();

    system("color 0B");//设置背景颜色 0--     B--
    system("pause");
    return 0;
}