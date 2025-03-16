#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;

ll tree[N<<4];  //线段树维护区间最小值，即该区间内机器的最早结束时间
int n,k;

int ans[N]; //记录每台机器处理的问题数
int Max = 0;

void pushup(int rt)
{
	tree[rt] = min(tree[rt<<1],tree[rt<<1|1]);
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
	pushup(rt);
}
void update(int l,int r,int pos,ll c,int rt)
{
	if(l == r){
		tree[rt] = c;
		return;
	}
	int mid = (l+r)>>1;
	if(pos <= mid) update(l,mid,pos,c,rt<<1);
	else update(mid+1,r,pos,c,rt<<1|1);
	pushup(rt);
}
ll query(int l,int r,int x,int y,int rt)
{
	if(x <= l && r <= y){
		return tree[rt];
	}
	int mid = (l+r)>>1;
	if(y <= mid)
		return query(l,mid,x,y,rt<<1);
	else if(x > mid)
		return query(mid+1,r,x,y,rt<<1|1);
	else{
		return min(query(l,mid,x,y,rt<<1),query(mid+1,r,x,y,rt<<1|1));
	}
}
int main()
{
	cin>>k>>n;
    //对于这种循环类型的操作，我们可以将它们拉长为原来的两倍，即在长度 k (i~i+k) 里面找
    //[0,k-1]--->[0,2*k-1]
	build(1,2*k,1);
	for(int i=0;i<n;i++){
		ll st,et;
		cin>>st>>et;
		if(query(1,2*k,1,2*k,1) > st) //如果区间内没有一台机器的结束时间早于该任务的开始时间，则抛弃该任务
			continue;
		int l = i%k+1; //该任务的初始在第 l 号机器上完成。+1 都将每台机器的编号右移一位即从 [0,2k-1]-->[1,2k]
		int r = i%k+k; //最后的可能是在第 r 号机器上完成
        //即该任务在 [l,r] 内的机器中完成
		while(l < r){  //二分查找满足的机器，
			int mid = (l+r)>>1;
			if(query(1,2*k,l,mid,1) <= st)  //优先找左区间的机器，因为要按顺序查找
				r = mid;
			else l = mid+1;
		}
		update(1,2*k,l,st+et,1);
		update(1,2*k,(l+k-1)%(2*k)+1,st+et,1);
		Max = max(Max,++ans[(l-1)%k]); //记录某一台机器完成任务数的最大值
	}
	int flag = 0;
	for(int i=0;i<k;i++){
		if(ans[i] == Max){
			if(!flag){
				printf("%d",i);
				flag = 1;
			}
			else{
				printf(" %d",i);
			}
		}
	}
	return 0;
}
/*

Sample Input
3 5
1 5
2 2
3 3
4 3
5 3
Sample Output
1
*/