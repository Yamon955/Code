#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int f[n+1],i;
	f[1]=f[0]=1;
	for(i=1;i<=n;i++){
		if(i-2>=0) f[i]=f[i-1]+f[i-2]; 
		else f[i]=f[i-1];
	}
	cout<<f[n];
	return 0;
 } 
