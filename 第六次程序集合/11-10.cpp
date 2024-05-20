#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>   
#include <map>
using namespace std;
 
int main()
{
	//locale loc(".936");
	//wcout.imbue(loc);
	puts(setlocale(LC_CTYPE, ""));    //设置中文编码方式
	wifstream in("习题11-10输入.txt");
	wofstream out("习题11-10输出.txt"); 
	//in.imbue(loc);
	//out.imbue(loc);
	wstring line;                //用来存储一行内容 
	map<wchar_t,int>counter;
	
	
	while(getline(in,line))
	{
		for(int i=0;i<line.length();++i)
		{
			counter[line[i]]++; 
		}
	}
	map<wchar_t,int>::iterator itor;
	int i=1;
	for(itor=counter.begin();itor!=counter.end();++itor,++i)  //迭代器
	{
		out<<itor->first<<"\t"<<itor->second<<"\t";
		if(i%4==0){
			out<<endl;
		}
	}
	in.close();
	out.close(); 
	
	return 0;
}