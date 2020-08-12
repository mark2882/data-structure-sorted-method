#if !defined(___class_stack)
#define ___class_stack
#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;

template<class Type>class stack{
	public:
		class EmptyErr{		};
		
		virtual ~stack(){		};
		virtual void Push(const Type)=0;
		virtual void Pop()=0;	//void??
};


template<class Type>class VecStack:
	public stack<Type>{
	vector<Type> stk;
	VecStack(const VecStack&);
	VecStack& operator=(const VecStack&);
	
	VecStack(){	}
	~VecStack(){	}
	void Push(const Type x){
		stk.push_back(x);
	}
	Type Pop(){
		if(stk.size()<=0)
			throw EmptyErr(this);
		Type x=stk.back();
		stk.pop_back();
		return x;	
	}
};
		
template<class Type>class LstStack:public stack<Type>{
	
	//template < class Type> 
	class Node{
		friend class LstStack<Type>;		//Type????? 
		Type* data;
		Node* next;
	public:
		Node(Type* d,Node* n):data(d), next(n){		}
	};
	Node<Type>* top;
	Node<Type>* dummy;
	
	LstStack(const LstStack&);
	LstStack& operator=(const LstStack&);
	
	public:
		LstStack(){
			top=dummy=new Node<Type>(NULL,NULL);
		}
		~LstStack(){
			Node<Type>* ptr=top;
			while(ptr!=dummy){
				Node<Type>* next=ptr->next;		//->????
				delete ptr->data;
				delete ptr;
				ptr=next;
			}
		delete dummy;	
		}
		void Push(const Type x){
			Node<Type>* ptr=top;
			top=new Node<Type>*(new Type(x), ptr);
		}
		Type Pop(){
			if(top==dummy)
				throw EmptyErr(this);
			else{
				Node<Type>* ptr=top->next;
				Type temp=*(top->data);
				delete top->data;
				delete top;
				top=ptr;
				return temp;
				
			}	
		}
};


#endif
