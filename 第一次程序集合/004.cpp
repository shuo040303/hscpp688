#include<stdio.h>
int main(){
    char str[32];
    int i,j,n,k=0;
    for(i=0;i<32;i++){
        scanf("%c",&str[i]);
        if(str[i]!='A'&&str[i]!='B'&&str[i]!='C'&&str[i]!='D')
            break;
    }
    int s=i;
    scanf("%d",&n);
    int a[32][2];
    for(i=0;i<s;i++){
        if(str[i]=='A'){
            a[i][0]=0;
            a[i][1]=0;
        }
        if(str[i]=='B'){
            a[i][0]=0;
            a[i][1]=1;
        }
        if(str[i]=='C'){
            a[i][0]=1;
            a[i][1]=0;
        }
        if(str[i]=='D'){
            a[i][0]=1;
            a[i][1]=1;
        }
    }
    int b[32][2];
    if(n>=0){
    for(i=0;i<s;i++){
        for(j=1;j>=0;j--){
            b[i][j]=n%2;
            n=(n-n%2)/2;
        }
    }
    }
    else if(n<0){
        n=-n;
    for(i=0;i<s;i++){
        for(j=1;j>=0;j--){
            b[i][j]=n%2;
            n=(n-n%2)/2;
        }
    }
    }
    for(i=0;i<s;i++){
        if(a[i][0]==b[i][0]&&a[i][1]==b[i][1])
            k++;
    }
    printf("%d",k);
}
