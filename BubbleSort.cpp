/*氣泡排序法(Bubble Sort)是排序演算法的一種，其觀念是逐次比較相鄰的兩筆資料，
然後根據排序條件交換(由小到大或由大到小)，一直交換到資料排序完成為止。*/

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void BubbleSort(int arr[],int size){
	int tmp;
	
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++)
			if(arr[j]>arr[j+1]){
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
		}
			
	}
	//return *arr;
}

int main(){
	srand(time(NULL));
	int *arr=new int [10];
	
	//delete [] arr;
	cout<<"original arr"<<endl;
	for(int i=0;i<10;i++){
		arr[i]=rand()%20;
		cout<<arr[i]<<" ";
	}
	//cout<<arr[10]<<"++++";
	BubbleSort(arr,10);
	
	cout<<"\nsorted arr"<<endl;
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
}

