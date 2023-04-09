#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class car;
class Boat
{
public:
	void setweight(int k)
	{
		weight = k;
	}
	int getweight()
		{
		return weight;
		}
	friend int gettotalweight(int  b, int c);
 
private:
	int weight;
};
class car
{
private:
	int weight;
public:
	void setweight(int k)
	{
		weight = k;
	}
	int getweight()
	{
		return weight;
	}
	friend int gettotalweight(int b, int c);
 
};
int gettotalweight(int b, int c)
{
	return b + c;
}
int main()
{
	Boat b1;
	b1.getweight();
	car c1;
	c1.getweight();
	cout << "b1 c1的重量和为：" << gettotalweight(1,2);
	return 0;
 
}