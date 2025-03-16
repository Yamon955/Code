//https://oi-wiki.org/ds/seg/
//https://blog.csdn.net/zearot/article/details/48299459  不错的博客
///https://www.cnblogs.com/yoyo-sincerely/p/5236523.html
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6;
int a[N];
int tree[N*4],lazy[N*4];
//tree[] 记录的是区间和   lazy[] 是修改标记
//更新
void pushUp(int rt)  //更新结点信息，这里是求和，也可以是别的(如求区间最值，求区间gcd)
{
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
//建树
void Build(int l,int r,int rt){ //l,r表示当前节点区间，rt表示当前节点编号
	if(l==r) {//若到达叶节点 
		tree[rt]=a[l];//储存数组值 
		return;
	}
	int mid =(l+r)>>1;
	//左右递归 
	Build(l,mid,rt<<1);
	Build(mid+1,r,rt<<1|1);
	//更新信息 
	pushUp(rt);
}
//下推标记
void pushDown(int l,int r,int rt)
{
	if(lazy[rt]){  //下推标记
		lazy[rt<<1] += lazy[rt];   //下推修改子结点的lazy
		lazy[rt<<1|1] += lazy[rt];

		//修改子结点的 tree 使之与对应的 lazy 标记相对应
		int mid = (l+r)>>1;
		tree[rt<<1] += lazy[rt]*(mid-l+1);
		tree[rt<<1|1] += lazy[rt]*(r-mid);
		lazy[rt] = 0;  //清除本结点的 lazy 标记
	}
}
//区间修改 ： a[x....y] += c
void update(int l,int r,int x,int y,int c,int rt) //l,r表示当前结点区间，x,y表示操作区间，rt表示当前结点编号
{
	if(x<=l && r<=y){  //如果本区间完全在操作区间[x,y]中
		tree[rt] += c*(r-l+1);  //更新数字和，向上保持正确
		lazy[rt] += c;  //增加lazy标记，表示本区间的 tree 值正确，子区间的 tree 值仍然需要根据 lazy 标记调整
		return;   //叶子结点会在这里返回，所以叶子节点不会进入到 pushDown() 中故不用判断叶子如果叶子结点 lazy[] 标记不为空向下传递会不会数组越界，不用考虑，因为叶子结点本身是不会进入到pushDown()函数中的
				//故单点更新, 不需要用到lazy标记，因为单点更新一定从叶子结点开始，没有办法向下推了，只能向上pushUp()维护
	}
	pushDown(l,r,rt); //下推标记
					  //// 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
	int mid = (l+r)>>1;
	//这里判断左右子树跟[x,y]有无交集，有交集才递归
	if(x <= mid) update(l,mid,x,y,c,rt<<1);
	if(y > mid)  update(mid+1,r,x,y,c,rt<<1|1);
	pushUp(rt);  //子结点更新完毕后，更新本结点信息
}

//区间查询：查询 a[x...y] 的和
int Query(int l,int r,int x,int y,int rt)
{
	if(x<=l && r<=y){   //若当前区间[l,r]包含在[x,y]中，直接返回
		return tree[rt];
	}
	pushDown(l,r,rt);  //下推标记，否则区间和 tree 值可能不正确
						//如果查询时还存在没有处理过的标记，则处理一下，防止出错
						// 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
	int mid = (l+r)>>1;
	int ans = 0;
	if(x <= mid) ans += Query(l,mid,x,y,rt<<1);
	if(y > mid) ans += Query(mid+1,r,x,y,rt<<1|1);
	return ans;
}