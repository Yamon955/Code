#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<stack>
using namespace std;
int cmp(char c)
{
	if(c=='=')         return 0;
	if(c=='-'||c=='+') return 1;
	if(c=='*'||c=='/') return 2;
	return 0;
} 
void compute(stack<double>&num,stack<char>&op)
{
	double b=num.top();
	num.pop();
	double a=num.top();
	num.pop();
	switch(op.top())
	{
		case'+':num.push(a+b);break;
		case'-':num.push(a-b);break;
		case'*':num.push(a*b);break;
		case'/':num.push(a/b);break;
	}
	op.pop();
}
int main()
{
	string c;
	stack<double> num;
	stack<char> op;
	while(cin>>c)
	{
		if(c=="=") break;
	    int len=c.length();
	    for(int i=0;i<len;i++)
	    {
			if(isdigit(c[i]))
			{
				double number=atof(&c[i]); 
				while( i<len && (isdigit(c[i])||c[i]=='.') )  i++;
				i--;               //一定要回到当前字符 
				num.push(number);
			}
			else 
			{
				if(c[i]=='(')       //左括号直接入栈 
				{       
					op.push(c[i]);
				}
				else if(c[i]==')')  //右括号 出栈计算直到左括号为止 
				{   
					while(op.top()!='(') compute(num,op);
					op.pop();
				}
				else if(op.empty()||cmp(c[i])>cmp(op.top()))  //栈空或者当前字符比栈顶字符优先级要高 ，直接入栈 
				{
					op.push(c[i]);
				}
				else //当前字符比栈顶字符优先级要低或者级别相同，那就出栈计算
				{ 
					while(!op.empty()&&cmp(c[i])<=cmp(op.top())) compute(num,op);
					op.push(c[i]);
				}
			}
	    }
	    op.pop();
	    printf("%.2f\n",num.top());
	    num.pop();
    } 
	return 0;
}
 
