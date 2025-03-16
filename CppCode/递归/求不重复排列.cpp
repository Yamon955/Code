#include<iostream>
using namespace std;
int n,k;
int f[100],v[100];
void dfs(int start,int count)
{
	if(count==k){
		for(int i=1;i<=count;i++){
			cout<<v[i];
		}
		cout<<endl;
		return;
	} 
	for(int i=start;i<=n;i++){
		v[count+1]=f[i];
		dfs(i+1,count+1);
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>f[i];
	dfs(1,0);
	return 0;
}
