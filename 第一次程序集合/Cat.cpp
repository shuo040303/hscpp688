#include <iostream>
using namespace std;
class cat{//创建一个名为cat的类
public:
	cat(int age):age (age){
	numofcats++;}//构造函数使用初始化列表来初始化私有数据成员age
	static int getnumofcats(){return numofcats;}//静态成员函数返回numofcats的值
	~cat(){numofcats--;}//析构函数销毁对象并让numofcats-1
	int getage(){return age;}//成员函数返回age的值
private:
	static int numofcats;
	int age;
};
int cat::numofcats=0;
int main()
{
	cat a=15;
	cat b=23;
	cout<<"总共有"<<cat::getnumofcats()<<"只猫"<<endl;
	cout<<"cat a的年龄是"<<a.getage()<<endl;
	cout<<"cat b的年龄是"<<b.getage()<<endl;
	return 0;
}