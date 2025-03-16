#include<cstdio>
#include<iostream>
#include<malloc.h>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ok 1
#define error 0
//////////////////////////////////////////////////////////////////
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;//���Һ���ָ�� 
}BiTNode, *BiTree;
/////////////////////////////////////////////////////////////////////////// 
typedef struct{
	char* top;
	char* base;
	int stacksize;
}Stack;//�����ջ 
typedef struct{
	BiTree* top;
	BiTree* base;
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
	s.base=(BiTree *)malloc(STACK_INIT_SIZE*sizeof(BiTree));
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
int push(stack &s,BiTree e) //��������ջ 
{
	if(s.top-s.base>=s.stacksize){
		s.base=(BiTree *)realloc(s.base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(BiTree));
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
int pop(stack &s,BiTree &e)//��������ջ 
{
	if(s.top==s.base) return error;
	e=*--s.top;
	return ok;
}
BiTree gettop(stack &s)//ȡ������ջ�� 
{
	BiTree *p;
	p=s.top-1;
		return *p;
}
char Gettop(Stack &s)//ȡ������ջ�� 
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
BiTree Bulid(char c)//����һ��ֻ���и��ڵ��ַ�c�Ķ����� 
{
	BiTree T;
	T=(BiTree)malloc(sizeof(BiTNode));
	T->data=c;
	T->lchild=NULL;
	T->rchild=NULL;
	return T;
	
 } 
 BiTree  expression(char ch)//�������ʽ������ 
{
	Stack OPTR;
	stack EXPT;
	Initstack(OPTR);
	initstack(EXPT);
	char c;
	BiTree a,b;
	Push(OPTR,'=');
	while(ch!='='||Gettop(OPTR)!='='){
		if(!In(ch))  {
		push(EXPT,Bulid(ch));//��ֻ�������ڵ��ַ�ch�Ķ�������ջ 
		cin>>ch;
	 	}
		else 
			switch(Precede(Gettop(OPTR),ch)){
				case'<':
					Push(OPTR,ch);
					cin>>ch;
					break;
				case'=':
					Pop(OPTR,c);
					cin>>ch;
					break;
				case'>':
					Pop(OPTR,c);
					pop(EXPT,a);
					pop(EXPT,b);//�Գ�ջ�������ַ�����һ�ö����� 
					BiTree p=(BiTree)malloc(sizeof(BiTNode));
					p->data=c;
					p->lchild=b;
					p->rchild=a; 
					push(EXPT,p);//�������Ķ��������ڵ���ջ 
					break;
			}		
   }
   return gettop(EXPT);//����ִ�е����EXPT������ջ��ֻ��һ�������ı��ʽ����������������� 
}
int operate(int a,char ch,int b)//���㺯�� 
{
	int v;
	switch(ch){
		case'+':v=a+b;break;
		case'-':v=a-b;break;
		case'*':v=a*b;break;
		case'/':v=a/b;break;
	}
	return v;
}
int cul(BiTree &T)//������ʽ�������Ľ�� 
{
	int lvalue,rvalue;
	if(T){
		if(In(T->data)){
			lvalue=cul(T->lchild);//������������ 
			rvalue=cul(T->rchild);//������������ 
			return operate(lvalue,T->data,rvalue);
		}
		else   return T->data-'0';
	}
}
void show_answer(char ch)//������ʽ��� 
{
	BiTree a;
	a=expression(ch);
	cout<<cul(a)<<endl;
}
int main()
{
	char ch;
	cin>>ch;
	while(ch!='='){//������ĵ�һ���ַ�Ϊ=ʱ����������� 
		show_answer(ch);
		cin>>ch;
	}
	return 0;
}
