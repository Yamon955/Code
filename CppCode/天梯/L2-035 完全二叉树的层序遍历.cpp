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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e5+50;

int n;
int a[N];
//完全二叉树采用顺序存储方式，如果有左孩子，则编号为2i，如果有右孩子，编号为2i+1，/
//然后按照后序遍历的方式（左右根），进行输入，最后顺序输出即可。
void creat(int i)
{
	if(i > n) return;
	creat(2*i);
	creat(2*i+1);
	cin>>a[i];
}
int main()
{
	cin>>n;
	creat(1);
	for(int i=1;i<=n;i++) 
		if(i == n) cout<<a[i];
		else cout<<a[i]<<" ";
}


