#include <iostream>
/*�q���ƧǼƦC���X�@�����C
�ѫ᩹�e�M�w�ƧǼƦC��������A����J�줣�j��ۤv�������ô��J����������F�Y���S���h���J�b�̫e���C
���ƥH�W�ʧ@���쥼�ƧǼƦC�����B�z�����C*/

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
			arr[j+1]=tmp;	//j+1����j-- ;
		
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
