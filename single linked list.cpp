#include<iostream>
using namespace std;

class linkedLst;
class linkNode{
	int data;
	linkNode* next;
	public:
		friend class linkedLst;
		//linkNode():data(0),next(0){};
		linkNode(int a):data(a),next(0){};
};

class linkedLst{
	linkNode *first; //用指標連結每個點 
	public:
		linkedLst():first(0){};		//初始化第一節點 
		
		void PrintLst(){
			if(first==0)		//first==0 
				cout<<"linkedLst is empty"<<endl;
			
			linkNode* current=first;
			while(current!=0){		//須以current為指標，才不會影響其他函式 
				cout<<current->data<<" ";
				current=current->next;
			}
				cout<<endl;
		}
		void PushBack(int x){
			linkNode *newNode=new linkNode(x);
			
			if (first == 0) { // 若list沒有node, 令newNode為first
        		first = newNode;
       			 return;
   				 }
			linkNode *current = first;
			while(current->next!=0){				//條件為current!=0;迴圈會跑到current=0 
				//cout<<current->data<<" ";		//直接秀current為位置地址 
				current=current->next;
			}
			current->next=newNode;
			//cout<<current<<"1"<<endl	;
			
		}
		void PushFront(int x){
			linkNode* previous=new linkNode(x);
			linkNode* current=first;
			
			previous->next=first;
			first=previous;
			
			
		}
		void DelNode(int x){
			linkNode* current=first, *previous=0;
			
			while(current!=0 && current->data!=x){
					
					previous=current;
					current=current->next;	//找到node後往後一步 
				}
				if(current==0)
					cout<<"no such node"<<endl;
				else if(current==first){
					first=current->next;
					delete current;
					current=0;			//指標指向null 
				}
				else{
					//previous=current;
					previous->next=current->next;
					delete current;
					current=0;
				}
			}
		void Clear(){
			if(first==0)
				cout<<"arr already empty"<<endl;
				
			while(first!=0){
				linkNode* current=first;
				first=first->next; //指標指向下個節點，直接刪除會出錯 
				delete current;
				current=0;
			}
			cout<<"clear complete"<<endl;
		}
		void Reverse(){
			linkNode *previous=0, *  current=first,  *preceding=first->next;
			//前previous,中current,後 preceding
			if(first==0||first->next==0)
				cout<<"the linklst is empty"<<endl;
			while(preceding!=0){
				current->next=previous;
				previous=current;
				current=preceding;
				preceding=preceding->next;	//做移動 
				
			}
			current->next= previous;		//preceding=0 
			first=current;	//反方向為起頭 
		}
};

int main(){
	linkedLst A;
	
	A.PushBack(2);
	A.PushBack(3);
	A.PushBack(4);
	/*A.PushFront(4);
	*/
	//A.DelNode(3);
	//A.Clear() ;
	//A.PushFront(4);
	A.Reverse();
	A.PrintLst();
	
	return 0;
}
