#include"XYZ.cpp"
int main (){
	X x(0);
	Y y;
	Z z;
	
	h(&x);   //调用类的友元函数h（X*）
	y.g(&x);   //调用Y的成员函数g(X*)是X的友元函数，实现对X的成员i加1 
	z.f(&x);	//	 类Z是类X的友元类，其成员函数f(X*)实现对X的成员i加5； 
	return 0;
} 
