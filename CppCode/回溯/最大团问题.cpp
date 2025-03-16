#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,cn,best;
int map[55][55];
int x[55];
int tmp[55],ans[55];
int flag = 0;
void backtrack(int i)
{
	if(i>n){
        best = cn;
		for(int i=1;i<=cn;i++) ans[i] = tmp[i];
        
		return;
	}
	int ok = 1;
	for(int j=1;j<i;j++){
		if(x[j]&&map[i][j]==0){
			ok = 0;
			break;
		}
	}
	if(ok){
		cn++;
		x[i] = 1;
        tmp[cn] = i;
		backtrack(i+1);
		x[i] = 0;
		cn--;
	}
	if(cn+n-i>best){
		x[i] = 0;
		backtrack(i+1);
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0) break;
		memset(x,0,sizeof(x));
        memset(map,0,sizeof(map));
        memset(tmp,0,sizeof(tmp));
		best = 0;
		cn = 0;
		for(int i=1;i<=m;i++){
			int u,v;
            cin>>u>>v;
            map[u][v] = map[v][u] = 1;
		}
		backtrack(1);
		cout<<best<<endl;
        for(int i=1;i<=best;i++) cout<<ans[i]<<" ";
	}
	return 0;
}