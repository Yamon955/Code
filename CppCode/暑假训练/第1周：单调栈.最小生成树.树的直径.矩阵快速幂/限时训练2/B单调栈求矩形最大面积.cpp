//51Nod 1158

#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int m,n;
int map[505][505];
int ans;
int solve(int x,int a[]){
	stack<int>st;
	int l[505],r[505];
	for(int i=1;i<=n;i++){
		while(!st.empty() && a[st.top()]>a[i]){
			int tmp = st.top();
			st.pop();
			r[tmp] = i-1; 
		}
		st.push(i);
	}
	while(!st.empty()){
		int tmp = st.top();
		st.pop();
		r[tmp] = n;
	}
	for(int i=n;i>=1;i--){
		while(!st.empty() && a[st.top()]>a[i]){
			int tmp = st.top();
			st.pop();
			l[tmp] = i+1; 
		}
		st.push(i);
	}
	while(!st.empty()){
		int tmp = st.top();
		st.pop();
		l[tmp] = 1;
	}
	int Max = 0;
	for(int i=1;i<=n;i++){
		int s = a[i]*(r[i]-l[i]+1);
		if(s>Max) Max = s;
	}
	return Max;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) cin>>map[i][j];
	}
	int a[505];
	for(int i=1;i<=m;i++){
		memset(a,0,sizeof(a));
		for(int k=1;k<=n;k++){
			for(int j=i;j>=1;j--){
				if(map[j][k]==0) break;
				a[k]++;
			}
			//cout<<a[k]<<" ";
		}
		//cout<<endl;
		ans = max(ans,solve(i,a));
	}
	cout<<ans;
	return 0;
}
/*
Sample Input
3 3
1 1 0
1 1 1
0 1 1
Sample Output
4
*/