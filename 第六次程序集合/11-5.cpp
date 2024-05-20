#include<iostream>
#include<fstream>
using namespace std;
 
int main()
{
	ofstream file1("test1.txt",ios::app);   //在文件尾添加数据 
	file1<<"已成功添加字符！"<<endl;
	file1.close();
	
	char ch;
	ifstream file2("test1.txt");       //程序输出文件内容 
	while(file2.get(ch))
		cout<<ch;
	file2.close(); 
	
	return 0;
	
} 