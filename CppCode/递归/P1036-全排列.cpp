#include<iostream>
#include<cstdio>
using namespace std;
int f[21];
int n,k,total=0;
int prime(int x)
{
	for(int i=2;i*i<x;i++)
		if(x%i==0) return 0;
	return 1;
}
void dfs(int start,int count,int sum)
{
	if(count==k) {
		if(prime(sum)){
			total++;
			return;
		}
	}
	for(int i=start;i<=n;i++){
		dfs(i+1,count+1,sum+f[i]);
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>f[i];
	dfs(1,0,0);
	cout<<total;
	return 0;
}
