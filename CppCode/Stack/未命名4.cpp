#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define SIZE 100
#define increase 50

typedef char ElemType;
typedef double ElemType2;
typedef int Status;


typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
}Sqstack;

typedef struct {
	ElemType2* base;
	ElemType2* top;
	int stacksize;
}sqstack;

void Initstack(Sqstack& s)//运算符初始化 
{
	s.base = (ElemType*)malloc(SIZE * sizeof(ElemType));
	if (!s.base)
		exit(1);
	s.top = s.base;
	s.stacksize = SIZE;
}

void Initstack(sqstack& s)//操作数初始化 
{
	s.base = (ElemType2*)malloc(SIZE * sizeof(ElemType2));
	if (!s.base)
		exit(1);
	s.top = s.base;
	s.stacksize = SIZE;
}



void push(Sqstack& s, ElemType e)//入栈 
{
	//cout << e << endl;
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (ElemType*)realloc(s.base, (SIZE + increase) * sizeof(ElemType));
		if (!s.base)
			exit(1);

		s.top = s.base + s.stacksize;
	}
	*s.top++ = e;
}

void push(sqstack& s, ElemType2 e)//入栈 
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (ElemType2*)realloc(s.base, (SIZE + increase) * sizeof(ElemType2));
		if (!s.base)
			exit(1);
		s.top = s.base + s.stacksize;
	}
	*s.top++ = e;
}

void pop(Sqstack& s, ElemType& x)//出栈 
{
	if (s.top == s.base)
	{
		printf("栈空1\n");
		exit(1);
	}
	x = *--s.top;
}

void pop(sqstack& s, ElemType2& x)//出栈 
{
	if (s.top == s.base)
	{
		printf("栈空2\n");
		exit(1);
	}
	s.top--;
	x = *s.top;
}

ElemType get(Sqstack& s)//取栈顶元素 
{
	ElemType* p;
	p = s.top - 1;
	return *p;
}

ElemType2 get(sqstack& s)//取栈顶元素 
{
	ElemType2* p;
	p = s.top - 1;
	return *p;
}


int precede(ElemType a, ElemType b)//'<'=0,'='=1,'>'=2
{
	if (b == '=')
		if (a == '=')
			return 1;
		else
			return 2;
	else if (b == ')')
		if (a == '(')
			return 1;
		else
			return 2;
	else if (b == '(')
		return 0;
	else if (b == '/')
		if (a == '+' || a == '-' || a == '(' || a == '=')
			return 0;
		else
			return 2;
	else if (b == '*')
		if (a == '+' || a == '-' || a == '(' || a == '=')
			return 0;
		else
			return 2;
	else if (b == '-')
		if (a == '(' || a == '=')
			return 0;
		else
			return 2;
	else if (b == '+')
		if (a == '(' || a == '=')
			return 0;
		else
			return 2;
}

ElemType2 operate(ElemType2 a, ElemType ch, ElemType2 b)
{
	ElemType2 v;
	//cout << a << ch << b << endl;
	switch (ch)
	{
		case '+':v = a + b; break;
		case '-':v = a - b; break;
		case '*':v = a * b; break;
		case '/':v = a / b; break;
	}
	return v;
}

bool In(ElemType a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')' || a == '=')
		return 1;
	return 0;
}

ElemType2 evaluateexpression()
{
	Sqstack OPTR;
	sqstack OPND;

	Initstack(OPTR);
	Initstack(OPND);

	ElemType2 a, b;
	ElemType c, A[100], i = 0, x, theta;
	push(OPTR, '=');
	c = getchar();

	while (c != '=' || get(OPTR) != '=')
	{
		if (!In(c))
		{
			while (!In(c))
			{
				A[i++] = c;
				c = getchar();
			}
			//cout << c << endl;
			push(OPND, atof(A));
			memset(A, 0, 100);
			i = 0;
		}
		else
			switch (precede(get(OPTR), c))
			{
				case 0:push(OPTR, c); c = getchar(); break;
				case 1:pop(OPTR, x); c = getchar(); break;
				case 2:
					pop(OPTR, theta);
					pop(OPND, b);
					pop(OPND, a);
					push(OPND, operate(a, theta, b));
					break;
			}
	}
	return get(OPND);
}

int main(void)
{
	ElemType2 B;
	B = evaluateexpression();
	cout << B << endl;

	return 0;
}
