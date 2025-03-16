#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef int SElemtype;
typedef int Status;
#define ok 1
#define error 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
	SElemtype* base;
	SElemtype* top;
	int stacksize;
}Sqstack;

Status Initstack(Sqstack& S)//构造一个空栈
{
	S.base = (SElemtype * )malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	if (!S.base) return error;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return ok;
}

Status Gettop(Sqstack S, SElemtype &e)//若栈不空，用e返回S的栈顶元素
{
	if (S.base == S.top) return error;
	e = *(S.top - 1);
	return ok;
}

Status Push(Sqstack &S, SElemtype e)//插入e为新的栈顶元素
{
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemtype*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemtype));
		if (!S.base) return error;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return ok;
}

Status Pop(Sqstack &S, SElemtype &e)//若栈不空，删除栈顶元素并用e返回其值
{
	if (S.base == S.top) return error;
	e = *--S.top;
	return ok;
}

Status disp(Sqstack &S)
{
	SElemtype *p,*q;
	p=S.base;
	q=S.top;
	while(p<q) cout<<*(p++)<<" ";
	return 0;
 } 


int main()
{
	int i, n, e, e1, e2,e3, a[100];
	Sqstack S;
	Initstack(S);
	cout << "输入要放入栈中的元素个数：";
	cin >> n;
	cout << "输入要放入栈中的元素:";
	for (i = 0; i < n; i++) {
		cin >> a[i];
		Push(S, a[i]);
	}
	cout << "当前栈序列：";
	disp(S); 
	cout<<endl;
	Gettop(S, e);
	cout << "当前栈顶元素值为："<< e << endl;
	Pop(S, e1);
	cout << "删除栈顶元素" << e1 << endl;
	Gettop(S, e2);
	cout << "删除栈顶元素之后的栈序列为：";
	disp(S);
	cout<<endl;
	cout<<"输入要插入的新的栈顶元素：";
	cin>>e3;
	Push(S,e3);
	cout<<"新的栈序列:";
	disp(S); 
	return 0;
}


