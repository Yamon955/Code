#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
int p[7]={30,35,15,5,10,20,25};
int m[100][100],s[100][100];
void MatrixChain(int *p,int n,int m[][100],int s[][100])
{
    for(int i=1;i<=n;i++) m[i][i]=0;
    for(int k=1;k<n;k++){
        for(int i=1;i<=n-k;i++){
            int j=i+k;
            m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int r=1;r<=k-1;r++){
                int t=m[i][i+r]+m[i+r+1][j]+p[i-1]*p[i+r]*p[j];
                if(t<m[i][j]){
                	m[i][j]=t;
                	s[i][j]=i+r;
				}
            }
        }
    } 
}
void Traceback(int i,int j,int s[][100])
{
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A "<<i<<","<<s[i][j];
	cout<<" and A "<<(s[i][j]+1)<<","<<j<<endl;
}
int main()
{
    int n=6;
    MatrixChain(p,n,m,s);
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++) cout<<m[i][j]<<" ";
    	cout<<endl;
	} 
	for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++) cout<<s[i][j]<<" ";
    	cout<<endl;
	} 
    Traceback(1,n,s);	
    return 0;
}