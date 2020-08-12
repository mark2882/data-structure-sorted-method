#include<iostream>
#include"virtual stack class.h"
using namespace std;

int main(){
	stack<int>* s=new VecStack<int>;
	int x;
	cin>>x;
	s->Push(x);
	cout<<"vector stack= "<<s->Pop()<<endl;
	
	return 0;
}
