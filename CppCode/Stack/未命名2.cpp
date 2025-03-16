#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
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
int main()
{
	cout<<operate(5.2,'*',3);
	return 0;
}
