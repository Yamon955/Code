#include<iostream>
#include<cstdio>
using namespace std;
int n,m,v[100],f[100];
void dfs(int start,int count)
{
	if(count==m+1){
		for(int i=1;i<=m;i++){
			cout<<f[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=start;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			f[count]=i;
			dfs(i+1,count+1);
			v[i]=0;
		}
	}
}
int main()
{
	cin>>n>>m;
	dfs(1,1);
	return 0;
}
