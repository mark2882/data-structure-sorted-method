/*選擇排序法(Selection Sort)是排序演算法的一種，其觀念是將資料分成"已排序"和"未排序"兩個部分，
並且依照順序從"未排序"中尋找最大(最小)值，加入到"已排序"資料的最後端
一直執行到排序結束也就是"未排序"資料為空的時候*/

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void Swap(int *arr1,int *arr2){
	int tmp=*arr1;
	*arr1=*arr2;
	*arr2=tmp;
	
}
void SelectionSort(int *arr,int size){
	int tmp;
	
	for(int i=0;i<size;i++){
		tmp=arr[i];
		int j=i+1;
		
		while(j<size){
			if(arr[j]<arr[i])
				Swap(&arr[i],&arr[j]);
			j++;
		}
	}
}

int main(){
	srand(time(NULL));
	int arr[10];
	
	cout<<"original arr"<<endl;
	for(int i=0;i<10;i++){
		arr[i]=rand()%20;
		cout<<arr[i]<<" ";
	}
	cout<<"\nsorted arr"<<endl;
	SelectionSort(arr,10);
	
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
		
}


