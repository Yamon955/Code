//poj 2352
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 32010;
int n,m;
int ans[N],a[N];
int lowbit(int x)
{
	return x&(-x);
 } 
void update(int pos,int x)
{
	for(int i=pos;i<=N;i+=lowbit(i))
		a[i] += x; 
 } 
int query(int pos)
{
	int ans = 0;
	for(int i=pos;i;i-=lowbit(i))
		ans += a[i];
	return ans; 
}
int main()
{
	mem(a,0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a++;  //防止 a==0  lowbit(0)会死循环
 		int w = query(a);
		//cout<<w<<endl;
		ans[w] ++;
		update(a,1);
	}
	for(int i=0;i<n;i++) printf("%d\n",ans[i]);

	return 0;
}
/*
样例输入
5
1 1
5 1
7 1
3 3
5 5
样例输出
1
2
1
1
0
*/