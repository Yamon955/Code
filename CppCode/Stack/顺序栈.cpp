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

Status Initstack(Sqstack& S)//����һ����ջ
{
	S.base = (SElemtype * )malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	if (!S.base) return error;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return ok;
}

Status Gettop(Sqstack S, SElemtype &e)//��ջ���գ���e����S��ջ��Ԫ��
{
	if (S.base == S.top) return error;
	e = *(S.top - 1);
	return ok;
}

Status Push(Sqstack &S, SElemtype e)//����eΪ�µ�ջ��Ԫ��
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

Status Pop(Sqstack &S, SElemtype &e)//��ջ���գ�ɾ��ջ��Ԫ�ز���e������ֵ
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
	cout << "����Ҫ����ջ�е�Ԫ�ظ�����";
	cin >> n;
	cout << "����Ҫ����ջ�е�Ԫ��:";
	for (i = 0; i < n; i++) {
		cin >> a[i];
		Push(S, a[i]);
	}
	cout << "��ǰջ���У�";
	disp(S); 
	cout<<endl;
	Gettop(S, e);
	cout << "��ǰջ��Ԫ��ֵΪ��"<< e << endl;
	Pop(S, e1);
	cout << "ɾ��ջ��Ԫ��" << e1 << endl;
	Gettop(S, e2);
	cout << "ɾ��ջ��Ԫ��֮���ջ����Ϊ��";
	disp(S);
	cout<<endl;
	cout<<"����Ҫ������µ�ջ��Ԫ�أ�";
	cin>>e3;
	Push(S,e3);
	cout<<"�µ�ջ����:";
	disp(S); 
	return 0;
}


