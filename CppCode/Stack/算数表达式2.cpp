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
}Stack;//�����ջ 
typedef struct{
	double* top;
	double* base;
	int stacksize;
}stack;//������ջ
int Initstack(Stack &s)//��ʼ�������ջ 
{
	s.base=(char *)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!s.base) return error;
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return ok;
}
int initstack(stack &s)//��ʼ��������ջ 
{
	s.base=(double *)malloc(STACK_INIT_SIZE*sizeof(double));
	if(!s.base) return error;
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return ok;
}
int Push(Stack &s,char e)//�������ջ 
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
int push(stack &s,double e)//��������ջ 
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
int Pop(Stack &s,char &e)//�������ջ 
{
	if(s.top==s.base) return error;
	e=*--s.top;
	return ok;
}
int pop(stack &s,double &e)//��������ջ 
{
	if(s.top==s.base) return error;
	e=*--s.top;
	return ok;
}
double gettop(stack &s)//ȡ������ջ�� 
{
	if(s.base!=s.top)
		return *(s.top-1);
}
char Gettop(Stack &s)//ȡ�����ջ�� 
{
	if(s.base!=s.top)
		return *(s.top-1);
}
char Precede(char e,char c)//�ж�����������뵱ǰջ������������ȼ� 
{
	char f;
	switch(c){
		case'+':
			if(e=='('||e=='=') f='<';
		    else               f='>';
		    break;
		case'-':
			if(e=='('||e=='=') f='<';
		    else               f='>';
		    break;
		case'*':
			if(e=='+'||e=='-'||e=='('||e=='=') f='<';
			else                               f='>';
		    break;
		case'/':
			if(e=='+'||e=='-'||e=='('||e=='=') f='<';
		    else                               f='>';
		    break;
		case'(':
			if(e==')') return error;
		    else     f='<';
		    break;
		case')':
			if(e=='(') f='=';
		    else if(e=='=') return error;
		    else   f='>';
		    break;
		case'=':    
			if(e=='=') f='=';
		    else if(e=='(') return error;
		    else       f='>';
		    break;
	}
	return f;	
}
double operate(double a1,char theta,double b1)//��a1 'theta' b1�����㺯�� 
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
int In(char c)//�ж��Ƿ�������� 
{
	switch(c){
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'=':return ok;
			break;
		default:return error;
	}
}
int evaluateExpression(char c)//��׺���ʽ��ֵ���� 
{
	Stack s;
	stack t;
	Initstack(s);//�����ջ 
	initstack(t);//������ջ 
    Push(s,'='); 
    char e,x;
    double a,b,m,n;
	while(c!='='||Gettop(s)!='='){
    	if(!In(c)){
    		m=0,n=0;//ƴ����mΪ�������֣�nΪС������ 
    		while(c!='.'&&c>='0'&&c<='9'){
    			m=m*10+c-'0';
    			cin>>c;
			}
			if(c=='.') cin>>c;
			int e=-1;
			while(c>='0'&&c<='9'){
				n=n+(c-'0')*pow(10,e);//pow(a,b)������ʾ  a^b (a��b�η�) 
				e--;
				cin>>c;
			}	
    		push(t,m+n);
		} 
		else {
			switch(Precede(Gettop(s),c)){
				case'<'://���Ĳ��������ȼ�����ջ�������������ջ 
					Push(s,c);
					cin>>c;
				    break;
				case'=': 
					Pop(s,e);//������
					cin>>c;
					break;
				case'>'://���Ĳ��������ȼ�����ջ���������������� 
					Pop(s,x);
					pop(t,a);
					pop(t,b);
					push(t,operate(b,x,a));//a,b˳���㷴 
					break;
			}
		}
	}
	printf("%.2lf\n",gettop(t));
    return 0;	
	
    
}
int main()
{
	char c;
	int i;
	for(i=0;;i++){
		cin>>c;
		if(c=='=') break;//�������룬�����ʽֻ��һ��'='ʱ���� 
		else       evaluateExpression(c);
	}
	return 0;
	
}
