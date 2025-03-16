/*
3
cout<<123
      132
      213
      231
      312
      321
    */
#include<iostream>
using namespace std;
int n;
int f[100],v[100];
void dfs(int dep)
{
	if(dep==n+1){
		for(int i=1;i<=n;i++)
			cout<<f[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			f[dep]=i;
			v[i]=1;
			dfs(dep+1);
			v[i]=0;//回溯
		}
	}
 } 
 int main()
 {
 	cin>>n;
 	dfs(1);
 	return 0;
  } 
