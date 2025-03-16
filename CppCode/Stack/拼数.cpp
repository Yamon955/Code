#include<cstdio>
#include<iostream> 
#include<math.h>
using namespace std;
int main()
{
	char a;
	double x=0,y=0;//分整数，小数两部分组成 
	a=getchar();
	while(a!='.'){
		x=x*10+a-'0';
		a=getchar();
	}
	if(a=='.') a=getchar();
	int e=-1;
	while(a!='#'){
		y=y+(a-'0')*pow(10,e);//pow(10,e)表示10^e;     pow(a,b)结果为a^b 
		e--;
		a=getchar();
	}
	cout<<x+y;
	return 0;
 } 
