#include<cstdio>
#include<iostream>
#include<string.h>
#include<malloc.h>
#include<math.h>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ok 1
#define error 0
typedef struct{
	char* top;
	char* base;
	int stacksize;
}Stack;//运算符栈 
typedef struct{
	double* top;
	double* base;
	int stacksize;
}stack;//操作数栈
int Initstack(Stack &s)
{
	s.base=(char *)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!s.base) return error;
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return ok;
}
int initstack(stack &s)
{
	s.base=(double *)malloc(STACK_INIT_SIZE*sizeof(double));
	if(!s.base) return error;
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return ok;
}
int Push(Stack &s,char e)
{
	if(s.top-s.base>=s.stacksize){
		s.base=(char *)realloc(s.base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(char));
		if(!s.base) return error;
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCREMENT;
	}
	*s.top++=e;
	return ok;
}
int push(stack &s,double e)
{
	if(s.top-s.base>=s.stacksize){
		s.base=(double *)realloc(s.base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(double));
		if(!s.base) return error;
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCREMENT;
	}
	*s.top++=e;
	return ok;
}
int Pop(Stack &s,char &e)
{
	if(s.top==s.base) return error;
	e=*--s.top;
	return ok;
}
int pop(stack &s,double &e)
{
	if(s.top==s.base) return error;
	e=*--s.top;
	return ok;
}
double gettop(stack &s)
{
	if(s.base!=s.top)
		return *(s.top-1);
}
char Gettop(Stack &s)
{
	if(s.base!=s.top)
		return *(s.top-1);
}
char Precede(char e,char c)
{
	char f;
	switch(c){
		case'+':
			if(e=='('||e=='#') f='<';
		    else               f='>';
		    break;
		case'-':
			if(e=='('||e=='#') f='<';
		    else               f='>';
		    break;
		case'*':
			if(e=='+'||e=='-'||e=='('||e=='#') f='<';
			else                               f='>';
		    break;
		case'/':
			if(e=='+'||e=='-'||e=='('||e=='#') f='<';
		    else                               f='>';
		    break;
		case'(':
			if(e==')') return error;
		    else     f='<';
		    break;
		case')':
			if(e=='(') f='=';
		    else if(e=='#') return error;
		    else   f='>';
		    break;
		case'#':    
			if(e=='#') f='=';
		    else if(e=='(') return error;
		    else       f='>';
		    break;
	}
	return f;	
}
double operate(double a1,char theta,double b1)
{
	double c;
	switch(theta){
		case'+':
			c=a1+b1;
		    break;
		case'-':
			c=a1-b1;
			break;
		case'*':
			c=a1*b1;
		    break;
		case'/':
			c=a1/b1;
		    break;
	}
	return c;
}
int In(char c)
{
	switch(c){
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'#':return ok;
			break;
		default:return error;
	}
}
int main()
{
	Stack s;
	stack t;
	Initstack(s);//运算符栈 
	initstack(t);//操作数栈 
    Push(s,'#'); 
    char c,e,x;
    double a,b,m,n;
    cin>>c;
    while(c!='#'||Gettop(s)!='#'){
    	if(!In(c)){
    		m=0,n=0;//拼数，m为整数部分，n为小数部分 
    		while(c!='.'&&c>='0'&&c<='9'){
    			m=m*10+c-'0';
    			cin>>c;
			}
			if(c=='.') cin>>c;
			int e=-1;
			while(c>='0'&&c<='9'){
				n=n+(c-'0')*pow(10,e);//pow(a,b)函数表示  a^b (a的b次方) 
				e--;
				cin>>c;
			}	
    		push(t,m+n);
		} 
		else {
			switch(Precede(Gettop(s),c)){
				case'<'://来的操作符优先级低于栈顶操作符，则进栈 
					Push(s,c);
					cin>>c;
				    break;
				case'=': 
					Pop(s,e);//脱括号
					cin>>c;
					break;
				case'>'://来的操作符优先级高于栈顶操作符，则运算 
					Pop(s,x);
					pop(t,a);
					pop(t,b);
					push(t,operate(b,x,a));//a,b顺序别搞反 
					break;
			}
		}
	}
    cout<<gettop(t);
	return 0;
}
