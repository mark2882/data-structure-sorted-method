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
	linkNode *first; //�Ϋ��гs���C���I 
	public:
		linkedLst():first(0){};		//��l�ƲĤ@�`�I 
		
		void PrintLst(){
			if(first==0)		//first==0 
				cout<<"linkedLst is empty"<<endl;
			
			linkNode* current=first;
			while(current!=0){		//���Hcurrent�����СA�~���|�v�T��L�禡 
				cout<<current->data<<" ";
				current=current->next;
			}
				cout<<endl;
		}
		void PushBack(int x){
			linkNode *newNode=new linkNode(x);
			
			if (first == 0) { // �Ylist�S��node, �OnewNode��first
        		first = newNode;
       			 return;
   				 }
			linkNode *current = first;
			while(current->next!=0){				//����current!=0;�j��|�]��current=0 
				//cout<<current->data<<" ";		//�����qcurrent����m�a�} 
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
					current=current->next;	//���node�᩹��@�B 
				}
				if(current==0)
					cout<<"no such node"<<endl;
				else if(current==first){
					first=current->next;
					delete current;
					current=0;			//���Ы��Vnull 
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
				first=first->next; //���Ы��V�U�Ӹ`�I�A�����R���|�X�� 
				delete current;
				current=0;
			}
			cout<<"clear complete"<<endl;
		}
		void Reverse(){
			linkNode *previous=0, *  current=first,  *preceding=first->next;
			//�eprevious,��current,�� preceding
			if(first==0||first->next==0)
				cout<<"the linklst is empty"<<endl;
			while(preceding!=0){
				current->next=previous;
				previous=current;
				current=preceding;
				preceding=preceding->next;	//������ 
				
			}
			current->next= previous;		//preceding=0 
			first=current;	//�Ϥ�V���_�Y 
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
