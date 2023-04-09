#include <iostream>
#include <string>
#include<cstring>
using namespace std;


class Employee {
private:
	char name[20];
	char str[20];
	char city[20];
	char prov[20];
	char id[20];
public:
	Employee(const char*, const char*, const char*, const char*, const char*);
	void ChangeName(const char*);
	void display();
};

Employee::Employee(const char* na, const char*st, const char*ci, const char*pr, const char*i) {
	strcpy_s(name, na);
	strcpy_s(str,st);
	strcpy_s(city,ci);
	strcpy_s(prov,pr);
	strcpy_s(id,i);
}

void Employee::ChangeName(const char* cna) {//函数类型 类名 函数名 参量
	strcpy_s(name, cna);
}

void Employee::display() {
	cout << name << "  " << str << "  " << city << "  " << prov << "  " << id << endl;
}

int main() {
	Employee x("小新", "地球", "哈尔滨", "黑龙江", "001");
	x.display();//对象.函数名字()  调用函数
	x.ChangeName("小A");
	x.display();
	char name[20], str[20], city[20], prov[20], id[20];

	
}


