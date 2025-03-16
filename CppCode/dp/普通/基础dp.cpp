//HDU-1069
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
const int N = 35;
int n;
struct node{
	int l,w,h;
	node(){}
	node(int a,int b,int c){
		l = a;
		w = b;
		h = c;
	}
	bool operator<(const node &a)const{ 
		if(l != a.l) return l > a.l;  //先按长度从大到小排序
		if(w != a.w) return w > a.w;  //长度相同则宽度大的在前(这里排不排不重要)
	}
}; 
node block[N*6];
int dp[N*6];//表示前 i 块木板以第 j 块为顶的最大高度 
int main()
{
	int Case = 0;
	while(scanf("%d",&n)!=EOF){
		if(n == 0) break;
		int cnt = 0;
		mem(dp,0);
		for(int i=1;i<=n;i++){
			int l,w,h;
			scanf("%d%d%d",&l,&w,&h);
			block[cnt++] = node(l,w,h);
			block[cnt++] = node(l,h,w);
			block[cnt++] = node(w,l,h);
			block[cnt++] = node(w,h,l);
			block[cnt++] = node(h,w,l);
			block[cnt++] = node(h,l,w);
            //每种长方体有6种不同的形态 
		}
		sort(block,block+cnt);
		dp[0] = block[0].h;
		int Max;
		for(int i=1;i<cnt;i++){
			Max = 0;
			for(int j=0;j<i;j++){ //在第 i 块之前找到
				if(block[j].l > block[i].l && block[j].w > block[i].w)//判断条件,找到第 i 块可以放上去的第 j 块，并找出最大值Max 那么以第 i 块为顶的最大高度 = Max + 第 i 块的高度
					Max = max(dp[j],Max); 
			}
			dp[i] = block[i].h + Max;
		}
		Max = 0;
		for(int i=0;i<cnt;i++)
			Max = max(dp[i],Max);
		printf("Case %d: maximum height = %d\n",++Case,Max);
	}
	return 0;
}
/*
Sample Input
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
Sample Output
Case 1: maximum height = 40
Case 2: maximum height = 21
Case 3: maximum height = 28
Case 4: maximum height = 342
*/