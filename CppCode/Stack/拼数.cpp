#include<cstdio>
#include<iostream> 
#include<math.h>
using namespace std;
int main()
{
	char a;
	double x=0,y=0;//��������С����������� 
	a=getchar();
	while(a!='.'){
		x=x*10+a-'0';
		a=getchar();
	}
	if(a=='.') a=getchar();
	int e=-1;
	while(a!='#'){
		y=y+(a-'0')*pow(10,e);//pow(10,e)��ʾ10^e;     pow(a,b)���Ϊa^b 
		e--;
		a=getchar();
	}
	cout<<x+y;
	return 0;
 } 
