//https://vjudge.net/problem/51Nod-1126
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
const int N = 50,M=1e9+7;

typedef struct node{
	int m[N][N];
}Martix;

void creat_Martix(Martix& v,int a,int b,int c,int d)
{
	v.m[0][0] = a; v.m[0][1] = b;
	v.m[1][0] = c; v.m[1][1] = d;
}

Martix mul(Martix a,Martix b)  //矩阵乘法 
{
	Martix ans;
	creat_Martix(ans,0,0,0,0);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				ans.m[i][j] += a.m[i][k]*b.m[k][j];
				ans.m[i][j] %= 7;
				
			}
		}
	}
	return ans;
}

Martix qsm(Martix a,int b)  //矩阵快速幂，与普通快速幂相同 
{
	Martix ans;
	creat_Martix(ans,1,0,0,1);
	while(b){
		if(b&1) ans = mul(ans,a);
		a = mul(a,a);
		b >>= 1;
	}
	return ans;
}

int a,b,n;
Martix f,tmp,ans;
int main()
{
	cin>>a>>b>>n;
	creat_Martix(f,1,1,0,0);
	creat_Martix(tmp,a,1,b,0);
	tmp = qsm(tmp,n-2);
	ans = mul(f,tmp);
	
	//cout<<(B.m[0][0]%7+7)%7;  //防止出现负数
	while(ans.m[0][0] < 0) ans.m[0][0] += 7; //防止出现负数 
	cout<<ans.m[0][0];
}