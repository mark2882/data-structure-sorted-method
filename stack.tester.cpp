#include<string> 
#include<iostream>
#include"stackv1.h"
using namespace std;

int main(){
	
	string x;
	cout<<"input string"<<endl;
	cin>>x;
	Stack s(x.length());
	
	try{
		for(int i=0;i<x.length();i++)
			s.Push(x[i]);
		for(int i=0;i<x.length()+1;i++)
			s.Pop();	
	}
	catch(Stack::OverflowErr x){
		cout<<"stack already full\n"<<x.vec()<<endl;
	}
	catch(Stack::EmptyErr x){
		cout<<"stack already empty\n"<<x.vec()<<endl;
	}
	
	
	/*		//simple version
	int stack[3], stack_top;
	string cmd;
    int i;

    stack_top = 0;

    while( cin >> cmd )
    {
        if( cmd == "push" )
        {
            cin >> i;
            stack[stack_top] = i;
            stack_top++;//INDEX
            
            if(stack_top>4)
            	cout<<"overFlowErr\n";
        }
        else if( cmd == "pop" )
        {
            if( stack_top == 0 )
                cout << " pop: nothing in stack" << endl;
            else
            {
                cout << " pop: " << stack[stack_top-1] << endl;  
                stack_top--;
            }
		}
		else
		cout<<"please keyin cmd push/pop\n";
    }*/
	
	return 0;
}


