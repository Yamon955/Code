#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 2e5+5;
int n,m;
int a[N],b[N];
int p[N],vis[N],ans[N],op[N];
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i] = i;
	for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++) cin>>op[i];
	for(int i=m;i>=1;i--){
		if(vis[op[i]]) {
			cout<<"不可能"<<endl;
			return 0;
		}
		vis[op[i]] = 1;
		if(find(a[op[i]]) != find(b[op[i]])){
			ans[i] = 0;
			p[find(a[op[i]])] = find(b[op[i]]);
		} 
		else ans[i] = 1;

	} 
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
/*
qduoj 101018
克里斯博弈
Description

如题目所说，这是一场克雷斯博弈。( 克雷斯博弈是军事博弈，是基于现有情况下，一方防守要道，一方进攻要道的战略

博弈 )。若是最后所有的要道都被攻方破坏掉了，那么攻方赢，否则白方赢。

初始状态，守方m条要道连接n座城镇，保证n座城镇之间是连通的。攻方进攻q次，每次随意进攻守方的交通要道。

可是守方凭借突出的情报收集能力，预先知道了攻方q次进攻的具体目标。而攻方凭借强大的重火力，对要道的进攻可谓是

攻之必毁。若攻方赢，输出每次进攻摧毁要道后，要道原先连接的两个城镇是否依旧连通。若是守方赢，输出“不可能”。


Input
第一行输入n，m。表示n座城镇，m条通道。

接下来m行，每行两个编号x y，表示城镇x,y之间有一条要道(无向)，要道的编号按照输入的循序从 1 逐渐增加 ( 1 ，2 ，3 ... m )

接下来q行，每行一个要道编号i，表示攻方要进攻的要道编号。攻方的进攻顺序与输入顺序一致。

（ n,m<=2e5，q=m ）


Output
若攻方赢，输出每次进攻摧毁要道后，要道原先连接的两个城镇是否依旧连通，连通输出1，否则输出0。

若是白方赢，输出“不可能”。


Sample Input 1 

4 3
1 2
2 3
3 4
1
2
3
Sample Output 1

0 0 0
Hint

q=m，攻方摧毁全部要道。

初始状态：1-2-3-4。

第一次进攻，攻方进攻1号要道，状态变为 1 2-3-4，1 2两城镇变为不连通，输出0。

第二次进攻，攻方进攻2号要道，状态变为 1 2 3-4，2 3两城镇变为不连通，输出0。

第三次进攻，攻方进攻3号要道，状态变为 1 2 3 4，3 4两城镇变为不连通，输出0。
*/