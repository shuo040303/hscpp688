#include<iostream>
#include<fstream>
using namespace std;
 
int main()
{
 
	ofstream file1("test1.txt");
	file1<<"已成功写入文件！"<<endl;
	file1.close();
	return 0;
	
} 