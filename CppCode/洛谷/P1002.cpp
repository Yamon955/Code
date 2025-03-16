#include<iostream>
using namespace std;
long long  f[100][100];
int main()
{
	
	long long m,n,m1,m2;
	int i,j;
	cin>>m>>n>>m1>>m2;
	for(i=0;i<=m;i++)
		for(j=0;j<=n;j++){
			if(i==0&&j==0) f[i][j]=0; 
			else if((i==0&&j!=0)||(i!=0&&j==0)) f[i][j]=1;
			else f[i][j]=f[i-1][j]+f[i][j-1];
			if((i==m1&&j==m2)||(i==m1+2&&j==m2+1)||(i==m1+1&&j==m2+2)||(i==m1-1&&j==m2+2)||(i==m1-2&&j==m2+1)||(i==m1-2&&j==m2-1)||(i==m1-1&&j==m2-2)||(i==m1+1&&j==m2-2)||(i==m1+2&&j==m2-1))
				f[i][j]=0;
		}
	cout<<f[m][n];
	return 0;
}
