//HDU 1556
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
int n,m;
int tree[N<<2],lazy[N<<2];
int a[N];
int Max;
void pushup(int rt)
{
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void pushdown(int l,int r,int rt)
{
	if(lazy[rt]){
		int mid = (l+r)>>1;
		tree[rt<<1] += lazy[rt]*(mid-l+1);
		tree[rt<<1|1] += lazy[rt]*(r-mid);
		lazy[rt<<1] += lazy[rt];
		lazy[rt<<1|1] += lazy[rt];
		lazy[rt] = 0;
	}
 } 
//void build(int l,int r,int rt)
//{
//	if(l == r){
//		tree[rt] = 0;
//		return ;
//	}
//	int mid = (l+r)>>1;
//	build(l,mid,rt<<1);
//	build(mid+1,r,rt<<1|1);
//	pushup(rt);
//}
void update(int l,int r,int x,int y,int c,int rt)
{
	if(x<=l && r<=y){
		tree[rt] += c*(r-l+1);
		lazy[rt] += c;
		return; 
	}
	pushdown(l,r,rt);
	int mid = (l+r)>>1;
	if(x <= mid) update(l,mid,x,y,c,rt<<1);
	if(y > mid) update(mid+1,r,x,y,c,rt<<1|1);
	pushup(rt);
}
ll query(int l,int r,int x,int y,int rt)
{
	if(x<=l && r<=y){
		return tree[rt];
	}
	pushdown(l,r,rt);
	int mid = (l+r)>>1;
	ll ans = 0;
	if(x <= mid) 
		ans += query(l,mid,x,y,rt<<1);
	if(y > mid)
		ans += query(mid+1,r,x,y,rt<<1|1);
	return ans;
 } 
int main()
{
	while(cin>>n){
		if(n == 0) break;
		mem(tree,0);
		mem(lazy,0);
		
		for(int i=1;i<=n;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			update(1,n,l,r,1,1);
		}
		//cout<<Max<<endl; 
		for(int i=1;i<=n;i++){
			if(i!=1)
				cout<<" "<<query(1,n,i,i,1);
			else cout<<query(1,n,i,i,1);
		}
		cout<<endl;
	}

	return 0;
}
/*
Sample Input
3
1 1
2 2
3 3
3
1 1
1 2
1 3
0
Sample Output
1 1 1
3 2 1
*/