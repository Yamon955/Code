#include<stdio.h>
#include<iostream>
using namespace std;

int f(int x)
{
	int flag;
	if(x%2==0) flag=1;
	else       flag=0;
	return flag;
}
int main()
{
	int n,i,sum=0;
	cin>>n;
	if(n==1) cout<<n<<"/"<<n;
	else{
		for(i=1;;i++)
	   {
		sum+=i;
		if(sum>n) break;
	   }
	if(f(i)==1){
		n=n-(sum-i);
		if(n==0) cout<<"1"<<"/"<<i-1;
		else     cout<<n<<"/"<<i+1-n;	
	  }
	else{
		n=n-(sum-i);
		if(n==0) cout<<i-1<<"/"<<1;
		else     cout<<i+1-n<<"/"<<n;
	   }
	}
	return 0;
 } 
