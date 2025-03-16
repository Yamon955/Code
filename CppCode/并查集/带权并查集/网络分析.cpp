//题目链接 https://www.dotcpp.com/oj/problem2579.html
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
#include<sstream>
#define mem(a,b) memset(a,b,sizeof a);
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e5+50;

int n,m;
int p[N]; 
int value[N];//表示当前节点传送的信息量
int dis[N];  //用来维护与根节点的差值，即当前节点在连接根节点之前已经传送的信息量或者根节点已经传送的信息量

int find(int x)
{
	if(x != p[x]){
		int tmp = p[x];  //先保存 x 个父节点，因为接下来的更新过程 p[x] 会变成根节点
		p[x] = find(p[x]);
		dis[x] += dis[tmp];  //当前 x 与根节点的差值 += 其父节点与根节点的差值 --->路径压缩的时候回溯更新
	}
	return p[x];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i] = i;
	while(m --){
		int op,a,b;
		cin>>op>>a>>b;
		if(op == 1){
			int fa = find(a);
			int fb = find(b);
			if(fa != fb){
				p[fa] = fb;
				dis[fa] = value[fa] - value[fb];//很重要，表明两者之间的差值
                                                //如果为正数，说明在连接之前 fa 发送的信息量要高于 fb 发送的信息量
                                                //如果为负数，说明在连接之前 fb 发送的信息量要高于 fa 发送的信息量
                                                //最后输出为 value[find(i)] + dis[i]
			}
		}
		else{
			int fa = find(a);
			value[fa] += b;  //每次都加到根节点上，输出的时候直接找根节点，
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",value[find(i)] + dis[i]);
}

/*
样例输入
4 8
1 1 2
2 1 10
2 3 5
1 4 1
2 2 2
1 1 2
1 2 4
2 2 1
样例输出
13 13 5 3
*/