#include <iostream>
/*從未排序數列取出一元素。
由後往前和已排序數列元素比較，直到遇到不大於自己的元素並插入此元素之後；若都沒有則插入在最前面。
重複以上動作直到未排序數列全部處理完成。*/

using namespace std;
void PrintArray(int *arr, int size);
/*
void InsertionSort(int *arr, int size){

    for (int i = 1; i < size; i++) {//arr[i]
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0) {//arr[j]
            arr[j+1] = arr[j];
            cout<<"while: arr["<<j+1<<"]="<<arr[j+1]<<"\n";
            //cout<<arr<<"\n";
            
			j--;
        }
        arr[j+1] = key;
        cout<<"arr["<<j+1<<"]="<<arr[j+1]<<"\n";
    }
}*/
 
void InsertionSort(int *arr,int n){
	
	
	for(int i=1;i<n;i++){
		int tmp=arr[i];
		int j=i-1;
		
		while(arr[j]>tmp && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
			arr[j+1]=tmp;	//j+1彌補j-- ;
		
	}	
} 
void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}

int main(){
  int array[6] = { 5, 3, 1, 2, 6, 4 };
    std::cout << "original:\n";
    PrintArray(array, 6);

    InsertionSort(array, 6);

    std::cout << "sorted:\n";
    PrintArray(array, 6);
    
    //PrintArray(array, 6);
    return 0;
  //system("pause"); 
}
