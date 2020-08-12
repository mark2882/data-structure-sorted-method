/*��ܱƧǪk(Selection Sort)�O�ƧǺt��k���@�ءA���[���O�N��Ƥ���"�w�Ƨ�"�M"���Ƨ�"��ӳ����A
�åB�̷Ӷ��Ǳq"���Ƨ�"���M��̤j(�̤p)�ȡA�[�J��"�w�Ƨ�"��ƪ��̫��
�@�������Ƨǵ����]�N�O"���Ƨ�"��Ƭ��Ū��ɭ�*/

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


