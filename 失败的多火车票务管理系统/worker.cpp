#include<stdio.h>
#include"function1.cpp"
void worker(){
    printf("***************************************************************************\n");
    printf("****请选择您要执行的操作:A.火车时刻信息录入 B.火车时刻信息查询 C.统计******\n");
    printf("***************************************************************************\n");
    char wk=getchar();//输入身份选择的情况
    getchar();
    if(wk=='A'){
        printf("您正在进行火车时刻信息录入操作。\n");
        messageinput();//火车时刻信息录入
    }
    else if(wk=='B'){
        printf("您正在进行火车时刻信息查询操作。\n");
        messagelooking();//火车时刻信息查询
    }
    else if(wk=='C'){
        printf("您正在进行统计操作。\n");
        statistics();//统计车次
    }
    else{
        printf("输入有误，请重新选择！\n");
        worker();
    }
}