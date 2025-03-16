//HDU-1074
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
const int N = 18;
int dp[1<<N];
int n,T;
int pre[N<<N];
struct node{
	char na[105];
	int d;
	int c;
	bool operator<(const node &a)const{
		return strcmp(na,a.na) < 0;
	}
};
node Ns[N];
struct Node{
	int sum;
	int Min;
};
void print(int st)
{
	if(st == 0) return;
	int t = 0;
	for(int i=0;i<n;i++){
		if((st & (1<<i)) != 0 && (pre[st] & (1<<i)) == 0){
			t = i;
			break;
		}
	}
	print(pre[st]);
	printf("%s\n",Ns[t].na);
}
int main()
{
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s%d%d",&Ns[i].na,&Ns[i].d,&Ns[i].c);
		}
//		sort(Ns+1,Ns+n+1); 按照名字字典序排序，发现没有必要，因为输入的数据就是按照学科的名字字典序从小到大排好的
		mem(pre,0);
		mem(dp,0x3f); 

		dp[0] = 0; //初始化
		for(int st=0;st<(1<<n);st++){ //遍历 0~(1<<n)-1 种状态
			int sum = 0; //记录当前状态 st 已经花费的总天数
			for(int i=0;i<n;i++){  //遍历状态 st 已经完成的学科
				if(st & (1<<i)){ //如果 st 状态下当前第 i 个学科已经完成
					sum += Ns[i].c;   //将完成时间加到 sum 中
				}
			} 
			for(int i=0;i<n;i++){  //遍历状态 st 未完成的学科
				if( st & (1<<i) ) continue;  //如果该学科已完成则不用向下进行

				if(dp[st|(1<<i)] > dp[st] + max(0,sum+Ns[i].c-Ns[i].d)){  //择优选择，if改为 dp[st|(1<<i)] >= dp[st] + max(0,sum+Ns[i].c-Ns[i].d，就是输出最少减分的字典序最大输出
					dp[st|(1<<i)] = dp[st] + max(0,sum+Ns[i].c-Ns[i].d);
					//max(0,sum+Ns[i].c-Ns[i].d)  被扣分数最小是 0 ---->易忽略
					pre[st|(1<<i)] = st;  //记录 st|(1<<i) 状态是由 st 推出来的，是最佳的
				}
			}
		}
		cout<<dp[(1<<n)-1]<<endl;
		print((1<<n)-1);  //输出字典序最小的答案
	}
}
/*
Sample Input
2
3
Computer 3 3
English 20 1
Math 3 2
3
Computer 3 3
English 6 3
Math 6 3
 

Sample Output
2
Computer
Math
English
3
Computer
English
Math

Hint

In the second test case, both Computer->English->Math and Computer->Math->English leads to reduce 3 points, but the 
word "English" appears earlier than the word "Math", so we choose the first order. That is so-called alphabet order.
*/
