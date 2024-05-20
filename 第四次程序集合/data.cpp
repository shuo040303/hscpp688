#include<iostream> 
using namespace std;
 
template<class T>
void swapData(T &a,T &b)
{
	T t=a;
    a=b; 
	b=t;
} 
 
template<class T>
void insertSort(T a[],int n)
{
    int i,j,k;
	int tmp;
 
    for(i=1;i<n;i++) 
    {
		tmp = a[i];   //将array[i]保存在临时变量tmp中
        j = i - 1;
        while(j>=0 && tmp<a[j]) {	
            a[j+1] = a[j--];    //循环找到array[i]应该放置的位置
		}
        a[j+1] = tmp;	/*将元素tmp插入指定位置*/
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
	insertSort(a,20);
	
	cout<<"排序后的数据："<<endl; 
	for(int i=0; i<20; i++)
		cout<<a[i]<<" ";
	cout<<endl;
 
	return 0;
}
 
 