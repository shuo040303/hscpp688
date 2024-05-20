#include<iostream> 
using namespace std;
 
template<class T>
void swapData(T &a,T &b)
{
	T t=a;
    a=b; 
	b=t;
} 
/*直接选择排序,要求：小的在前大的在后*/
template<class T>
void selectSort(T a[],int n)
{
    int i, j, k, t;
	int tmp;
 
    for(i=0; i<n-1; i++)	/*i比j小1，所以i范围是0~n-1*/
	{
		k=i;	/*最小值下标*/
		for(j=i+1; j<n; j++)
			if(a[j]<a[k])
				k=j;		
		swapData(a[i],a[k]);
		for(k=0;k<n;k++)
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
	selectSort(a,20);
	
	cout<<"排序后的数据："<<endl; 
	for(int i=0; i<20; i++)
		cout<<a[i]<<" ";
	cout<<endl;
 
	return 0;
}
 