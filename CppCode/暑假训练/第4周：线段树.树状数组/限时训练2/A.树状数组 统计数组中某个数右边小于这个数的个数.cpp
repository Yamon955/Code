//https://vjudge.net/contest/454204

//HDU 5775
// 不难发现，对于一个数i，其运动轨迹是先向右移再向左移，原数组i右面有几个比他小的就右移多少格，最左端由i原来的位置和最后的位置最小值决定。
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
const int N = 1e5+5;
int n,m,T; 
int L[N],R[N],c[N];
struct node{
	int x;
	int idx;
}; 
node a[N];
int lowbit(int x)
{
	return x&(-x);
 } 
void update(int pos,int x)
{
	for(int i=pos;i<=N;i+=lowbit(i))
		c[i] += x; 
 } 
int query(int pos)
{
	int ans = 0;
	for(int i=pos;i;i-=lowbit(i))
		ans += c[i];
	return ans; 
}
int main()
{
	scanf("%d",&T);
	int cnt = 0;
	while(T--){
		scanf("%d",&n);
		mem(c,0);
		mem(a,0);
		mem(L,0);
		mem(R,0);
		for(int i=0;i<=n;i++){
			a[i].x = 0;
			a[i].idx = 0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].x);
			a[i].idx = i;
			L[a[i].x] = min(a[i].x,i);
		}
		for(int i=n;i>=1;i--){
			int w = query(a[i].x);
			R[a[i].x] = a[i].idx+w;
			update(a[i].x,1);
		}
		cout<<"Case #"<<(++cnt)<<": ";
		for(int i=1;i<=n;i++){
			if(i<n)
				cout<<abs(L[i]-R[i])<<" ";
			else cout<<abs(L[i]-R[i]);
		}
		cout<<endl;
	}
	return 0;
 } 
/*
Sample Input
2
3
3 1 2
3
1 2 3
Sample Output
Case #1: 1 1 2
Case #2: 0 0 0


*/