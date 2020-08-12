#include<iostream>

#include<ctime>
#include<cstdlib>
using namespace std;
/*1.�q�ƦC���D��@�Ӥ����A�٬���ǭ�(Pivot)
�ֳt�ƧǪk���Ĳv�M�ҿ������ǭ�(Pivot)���ܤj�����Y�A�i�H�C���������ƩάO�Ĥ@�ӼƭȩάO�̫�@�ӼƭȩάO�üƿ�ܡC

2.�N�Ҧ����ǭȤp�������\�b����I����Φ����l�ǦC�C�N�Ҧ����ǭȤj�������\�b��ǭȥk��Φ��k�l�ǦC�C

3.���O�索�l�ǦC�M�k�l�ǦC���ƤW�z��ӨB�J���쥪�l�ǦC�Υk�l�ǦC�u�Ѥ@�ӼƭȩΨS���ƭȡC*/


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
        QuickSort(arr, pivot + 1, end);		//�j�k 
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
