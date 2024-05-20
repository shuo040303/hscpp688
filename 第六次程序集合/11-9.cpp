#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip> //函数setw() 输出格式控制
using namespace std;
 
int main(){
	/*(1)打开输入文件*/
	ifstream infile;
	infile.open("abc.txt");//outfile.open("abc.txt",ios::in); //默认方式，两种都可以 
	if(!infile){		   
		cout<<"输入文件abc.txt打开失败!\n";		   
		return 1;		   
	}
	  
	/*(2)打开输出文件*/
	ofstream outfile;
	outfile.open("abc_back.txt",ios::out);
	if(!outfile){
		cout<<"输出文件abc_back.txt打开失败!\n";
		return 1;
	}
	
	/*(3)复制行，并在行头添加行号*/
	int num_line=1;	//行号计数器
	char buffer[256]; //行拷贝缓冲区
	while(!infile.eof()){
		/*(3.1)读取1行，进行判断*/
		if (!infile.getline(buffer, sizeof(buffer))){
			//cout<<"已经到达文件结尾，文件读取失败，退出循环！";
			break;
		}
 
		/*(3.2)写出构造的新行*/
		while(infile.getline(buffer,256))
	    {
	    	outfile.width(10);     //设置域宽为10 
	        outfile << num_line++ << ". ";
	        outfile << buffer <<endl;    //将从abc.txt读入的内容写入abc_back.txt中 
	    }
	}
    
	/*(4)文件关闭*/
	infile.close();
	outfile.close();
 
	cout<<"操作成功，程序结束！\n";
	return 0; 
}