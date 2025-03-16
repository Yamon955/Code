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
	struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode, *BiTree;
/////////////////////////////////////////////////////////////////////////// 
typedef struct{
	char* top;
	char* base;
	int stacksize;
}Stack;//运算符栈 
typedef struct{
	BiTree* top;
	BiTree* base;
	int stacksize;
}stack;//二叉树栈 
int Initstack(Stack &s)//初始化运算符栈 
{
	s.base=(char *)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!s.base) return error;
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return ok;
}
int initstack(stack &s)//初始化二叉树栈 
{
	s.base=(BiTree *)malloc(STACK_INIT_SIZE*sizeof(BiTree));
	if(!s.base) return error;
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return ok;
}
int Push(Stack &s,char e)//运算符进栈 
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
int push(stack &s,BiTree e) //二叉树进栈 
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
int Pop(Stack &s,char &e)//运算符出栈 
{
	if(s.top==s.base) return error;
	e=*--s.top;
	return ok;
}
int pop(stack &s,BiTree &e)//二叉树出栈 
{
	if(s.top==s.base) return error;
	e=*--s.top;
	return ok;
}
BiTree gettop(stack &s)//取操作数栈顶 
{
	BiTree *p;
	p=s.top-1;
		return *p;
}
char Gettop(Stack &s)//取二叉树栈顶 
{
	if(s.base!=s.top)
		return *(s.top-1);
}
char Precede(char e,char c)//判断来的运算符与当前栈顶运算符的优先级 
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
int In(char c)//判断是否是运算符 
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
BiTree Bulid(char c)//创建一个只含有根节点字符c的二叉树 
{
	BiTree T;
	T=(BiTree)malloc(sizeof(BiTNode));
	T->data=c;
	T->lchild=NULL;
	T->rchild=NULL;
	return T;
	
 } 
 BiTree  expression(char ch)//构建表达式二叉树 
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
		push(EXPT,Bulid(ch));//将只包含根节点字符ch的二叉树入栈 
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
					pop(EXPT,b);//以出栈的三个字符构建一棵二叉树 
					BiTree p=(BiTree)malloc(sizeof(BiTNode));
					p->data=c;
					p->lchild=b;
					p->rchild=a; 
					push(EXPT,p);//将构建的二叉树根节点入栈 
					break;
			}		
   }
   return gettop(EXPT);//函数执行到最后EXPT二叉树栈就只有一棵完整的表达式二叉树，返回这棵树 
}
int operate(int a,char ch,int b)//运算函数 
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
int cul(BiTree &T)//计算表达式二叉树的结果 
{
	int lvalue,rvalue;
	if(T){
		if(In(T->data)){
			lvalue=cul(T->lchild);//左子树运算结果 
			rvalue=cul(T->rchild);//右子树运算结果 
			return operate(lvalue,T->data,rvalue);
		}
		else   return T->data-'0';
	}
}
void show_answer(char ch)//输出表达式结果 
{
	BiTree a;
	a=expression(ch);
	cout<<cul(a)<<endl;
}
int main()
{
	char ch;
	cin>>ch;
	while(ch!='='){//当输入的第一个字符为=时多组输入结束 
		show_answer(ch);
		cin>>ch;
	}
	return 0;
}
