#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	for(a=123;a<=333;a++){
		b=2*a;
		c=3*a;
		if((a/100+a/10%10+a%10+b/100+b/10%10+b%10+c/100+c/10%10+c%10==1+2+3+4+5+6+7+8+9)&&((a/100)*(a/10%10)*(a%10)*(b/100)*(b/10%10)*(b%10)*(c/100)*(c/10%10)*(c%10)==(1)*(2)*(3)*(4)*(5)*(6)*(7)*(8)*(9)))
		  cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
 } 
