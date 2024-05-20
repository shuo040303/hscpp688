#include <iostream>
using namespace std;
template<class T>
//这里使用了冒泡法排序：
void swapData(T &a,T &b)
{
	T t=a;
    a=b; 
	b=t;
} 
    
template<class T>
void Bubblesort(T a[], int n)//用冒泡法对数组a的n个元素进行排序
{
	int i = n - 1;
 
	while (i > 0)
	{
		int lastExchangeIndex = 0;
		for (int j = 0; j < i; j++)
		    if (a[j+1]>a[j])
			{     
				swapData(a[j], a[j + 1]);
				lastExchangeIndex = j;
			}
		i = lastExchangeIndex;
		
		for(int k=0;k<n;k++)
			cout<<a[k]<<" ";
		cout<<endl;
	}  
}
 
int main()
{
	int a[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
	
	cout<<"排序前的数据："<<endl; 
	for(int i=0; i<20; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
	cout<<"进行排序："<<endl;
	Bubblesort(a,20);
	
	cout<<"排序后的数据："<<endl; 
	for(int i=0; i<20; i++)
		cout<<a[i]<<" ";
	cout<<endl;
 
	return 0;
}
 
 