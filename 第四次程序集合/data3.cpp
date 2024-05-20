#include<iostream>

using namespace std;

template<class T>

void BubbleSort(T list[], int n)
{
	for (int i = 0; i < n - 1; i++)  //冒泡
	{
		int t;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				t = list[j];
				list[j] = list[j + 1];
				list[j + 1] = t;
			}
		}
	}
}

template<class T>

int binSearch(T list[], int n, T key)
{
	int begin, mid, end;
	begin = 0;
	end = n - 1;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (key == list[mid])
			return mid;
		else if (key > list[mid])
			begin = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
}

int main()
{
	int data1[] = { 1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20 };
	int key, n = 20;

	BubbleSort(data1, n);     //冒泡
	
cout << "排序后的数组为：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << data1[i] << "  ";
	}

	cout << endl;
	cout << "请输入所要查找的数字：";
	cin >> key;
	cout << "在数组中的位置："<<binSearch(data1, n, key) << endl;
}
