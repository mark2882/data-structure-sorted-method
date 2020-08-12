#include<iostream>

#include<ctime>
#include<cstdlib>
using namespace std;
/*1.從數列中挑選一個元素，稱為基準值(Pivot)
快速排序法的效率和所選取的基準值(Pivot)有很大的關係，可以每次選取中位數或是第一個數值或是最後一個數值或是亂數選擇。

2.將所有比基準值小的元素擺在基準點左邊形成左子序列。將所有比基準值大的元素擺在基準值右邊形成右子序列。

3.分別對左子序列和右子序列重複上述兩個步驟直到左子序列或右子序列只剩一個數值或沒有數值。*/


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);		//迴歸 
    }
}
void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
    	/*srand(time(NULL));
    	arr[i]=rand()%20;*/
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {

    int n = 10;
    int arr[n]= {9, 4, 1, 6, 7, 3, 8, 2, 5};
    //int *arr={0};
    std::cout << "original:\n";
    /*for (int i = 0; i < 20; i++) {
    	srand(time(NULL));
    	arr[i]=rand()%20;
    	std::cout << arr[i] << " ";
    	}*/
		 
    PrintArray(arr, n);

    QuickSort(arr, 0, n-1);

    std::cout << "\nsorted:\n";
    PrintArray(arr, n);
    return 0;
}
