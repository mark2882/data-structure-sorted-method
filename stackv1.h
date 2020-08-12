#if !defined(___Class_Stack)
#define __Class_Stack

class Stack
{
int size;
int ptr;
int* stk;

Stack(const Stack&);
Stack& operator=(const Stack&);
public:
	explicit Stack(int sz):size(sz),ptr(0){stk=new int [size];	}
	~Stack(){delete [] stk;	}
	
	class OverflowErr{
		Stack *ident;		
		//string x="err occure\a";
		public:
			OverflowErr(Stack* p):ident(p){			}
			Stack* vec(){return ident;			}		//ªð¦^¿ù»~ªºstack ¦ì¸m
			//Stack* vec(){return x;			}
	};
	char &Push(const int& x){
		if(ptr>=size)
			throw OverflowErr(this);
		return stk[ptr++]=x;
	}
	class EmptyErr{
		Stack* ident;
		public:
			EmptyErr(Stack* p):ident(p){
			}
			Stack* vec(){return ident;			}
	};
	char& Pop(){
		if(ptr<=0)
			throw EmptyErr(this);
		return stk[ptr--]	;
	}
	
};


#endif	
