#include <iostream>
#include <String>
using namespace std;


int count(char *str){
		int n=0;
		for(int i=0;str[i];i++){
			if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
				n++;
			}
		}
		return n;
	}
	
int main(){
	
	
	char str[100];//定义一个字符数组存放字符串
	cout<<"please input an English sentence：";//提示输入
	gets(str);    //gets()可以输入空格' '，但是cin不能输入空格； 
	cout<<count(str);
	
	return 0;
}