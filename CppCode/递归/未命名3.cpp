#include<iostream>
#include<cstdio>
using namespace std;
int m;
int f[10],v[10];
void dfs(int x)
{
	if(x==m+1){
		for(int i=1;i<x;i++) printf("%5d",f[i]);
		cout<<endl; 
	}
	for(int i=1;i<=m;i++){
		if(v[i]==0){
			f[x]=i;
			v[i]=1;
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main()
{
	cin>>m;
	dfs(1);
	return 0;
}
