//https://www.luogu.com.cn/problem/P3390
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#define mem(a,b) memset(a,b,sizeof a);
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 105,M=1e9+7;

int n;
ll k;  //开long long 
typedef struct node{
	ll m[N][N];  //这里也要开 long long 
}Matrix;

Matrix mul(Matrix a,Matrix b)
{
	Matrix ans;
	mem(ans.m,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ans.m[i][j] += a.m[i][k]*b.m[k][j];  //可能会爆int，故要开longlong 
				ans.m[i][j] %= M;  //这里取模 
			}
		}
	}
	return ans;
}

Matrix qsm(Matrix a,ll b)
{
	Matrix ans;
	//单位矩阵，主对角线全为 1，其余全为 0 
	mem(ans.m,0);
	for(int i=0;i<n;i++) ans.m[i][i] = 1; 
	
	//矩阵快速幂，与普通快速幂相同，只不过乘法变为矩阵乘法 
	while(b){
		if(b&1)	ans = mul(ans,a);
		a = mul(a,a);
		b >>= 1;
	}
	return ans;
}
int main()
{
	cin>>n>>k;
	Matrix f;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>f.m[i][j];
	f = qsm(f,k);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<f.m[i][j]<<" ";
		cout<<endl;
	}
}