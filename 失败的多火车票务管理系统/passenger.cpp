#include<stdio.h>
#include"function2.cpp"
void passenger(){
    printf("***************************************************\n");
    printf("***请选择您的需要办理的业务:A.订票 B.退票 C.改签***\n");
    printf("***************************************************\n");
    char ps=getchar();//输入身份选择的情况
    getchar();
    if(ps=='A'){
        printf("\n");
        ding();//订票
    }
    else if(ps=='B'){
        printf("\n");
        tui();//退票
    }
    else if(ps=='C'){
        printf("\n");
        gai();//改签
    }
    else{
        printf("输入有误，请重新选择！\n");
        passenger();
    }
}