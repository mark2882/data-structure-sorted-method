#include <iostream>
using namespace std;


//循序搜尋法 
int linearSearch(int[], int, int);

int main() {

	const int size = 10;//陣列大小
	int search = 0;//想要找的值

	int arr[100];//初始化資料陣列

	for (int i = 0; i < size; i++)
	{
		arr[i] = 2 * i;//賦予陣列值: a[0]=0 a[1]=2 a[2]=4 ... a[99]=198
		cout<<arr[i]<<"　";
	}

	cout << "\nsearch the value:";
	cin >> search;
	int element = linearSearch(arr, search, size);

	if (element != -1)
	{
		cout << "Found value in index " << element << endl;
	}

	else
	{
		cout << "Value not found" << endl;
	}

	system("pause");

	return 0;
}
/*
int linearSearch(int data[], int key,int size)
{

	for (int index = 0; index < size; index++)
	{
		if (data[index]==key)
		{
			return index;
		}
	}
	return -1;
}*/
int linearSearch(int data[], int key,int size){
	for(int i=0;i<size;i++){
		if(key==data[i])
			return i;
			
	}
	return -1;
}






