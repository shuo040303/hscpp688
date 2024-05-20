//main.c
#include<iostream>
#include<cassert>
#include"LinkedList.h"
using namespace std;
 
template<typename T>       
class OrderList:public LinkedList<T>
{
public:
	void insertOrder(const T& item);
};
 
template<typename T>
void OrderList<T>::insertOrder(const T& item)
{
	this->reset();
	while (!this->endOfList())
	{
		if(item<this->data())
			break;
		this->next();
	}
	this->insertAt(item);
}
 
int main()
{
	OrderList<int>a;
	a.insertOrder(6);
	a.insertOrder(3);
	a.insertOrder(9);
	a.insertOrder(7);
	a.insertOrder(1);
	OrderList<int>b;
	b.insertOrder(5);
	b.insertOrder(8);
	b.insertOrder(4);
	b.insertOrder(2);
	b.insertOrder(0);
	
	cout<<"输入链表a中的元素为："; 
	a.reset();
	while (!a.endOfList())
	{
		cout<<a.data()<<" ";
		a.next();
	}
	
	cout<<endl<<"输入链表b中的元素为："; 
	b.reset();
	while (!b.endOfList())
	{
		a.insertOrder(b.data());
		cout<<b.data()<<" ";
		b.next();
	}
	
	cout<<endl<<"链表a,b合并后的元素为：";
	a.reset();
	while (!a.endOfList())
	{
		cout<<a.data()<<" ";
		a.next();
	}
	return 0;
}