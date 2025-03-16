//SPOJ - HORRIBLE
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+50;
ll T,n,m;
ll tree[N<<2],lazy[N<<2];
void pushUp(int rt)
{
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void pushDown(int l,int r,int rt)
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
void build(int l,int r,int rt)
{
	if(l == r){
		tree[rt] = 0;
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushUp(rt); 
 } 
void update(int l,int r,ll x,ll y,ll c,int rt)
{
	if(x<=l && r<=y){
		tree[rt] += 1ll*c*(r-l+1);
		lazy[rt] += c;
		return;
	}
	pushDown(l,r,rt);
	int mid = (l+r)>>1;
	if(x <= mid) update(l,mid,x,y,c,rt<<1);
	if(y > mid) update(mid+1,r,x,y,c,rt<<1|1);
	pushUp(rt); 
}
ll query(int l,int r,ll x,ll y,int rt)
{
	if(x<=l && r<=y){
		return tree[rt];
	}
	pushDown(l,r,rt);
	int mid = (l+r)>>1;
	ll ans = 0;
	if(x<=mid)  ans += query(l,mid,x,y,rt<<1);
	if(y>mid)  ans += query(mid+1,r,x,y,rt<<1|1);
	return ans; 
 } 
int main()
{
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i=0;i<=N*4-1;i++) {
			lazy[i] = 0; 
			tree[i] = 0;
		}
		build(1,n,1);
		while(m--){
			ll op,l,r,c;
			scanf("%lld%lld%lld",&op,&l,&r);
			if(l > r) swap(l,r);
			if(op == 0){
				scanf("%lld",&c);
				update(1,n,l,r,c,1);
			} 
			else{
				cout<<query(1,n,l,r,1)<<endl;
			}
			
		}
	}


	return 0;
}
/*
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8

Output:
80
508
*/