/*��w�ƧǪk(Bubble Sort)�O�ƧǺt��k���@�ءA���[���O�v������۾F���ⵧ��ơA
�M��ھڱƧǱ���洫(�Ѥp��j�ΥѤj��p)�A�@���洫���ƱƧǧ�������C*/

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

