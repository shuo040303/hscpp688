#include<iostream>
#include"LinkedList.h"
using namespace std;
int main() {
	LinkedList<int> a,b;
	cout << "输入链表a的元素：";
	for (int i = 0; i <5; i++)
	{
		int item;
		cin >> item;
		a.insertFront(item);
	}
	cout << "输入链表b的元素：";
	for (int i = 0; i < 5; i++)
	{
		int item;
		cin >> item;
		b.insertFront(item);
	}
    b.reset();
	if (!b.endOfList()) {
		for (int i = 0; i < b.getSize(); i++) {
			a.insertRear(b.data());
			b.next();
		}
	}
 
	cout << "输出链表b插入a队尾后的的元素：";
	a.reset();
	while (!a.endOfList()) {
		cout << a.data()<<" ";
		a.next();
	}
	return 0;
}