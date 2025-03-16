//POJ3254
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 13;
const int mod = 1e8;
int n,m,f[N][N],tol;
int dp[N][1<<N];
int v[1<<N];  //记录合法状态，tol计数
bool check1(int st)  //判断此状态 st 是否合法-->及不存在相邻的两个 1
{
   return (st & (st<<1)); //--->如果存在两个相邻 1，则会返回 true
}
bool check2(int i,int st)  //判断当前第 i 行的状态 st 是否合法， 
{
    for(int j=0;j<m;j++){
		if((st & (1<<j)) && f[i][j]==0) return false; //如果当前状态的第 j 位为 1，但是当前行的第 j 位为 0,二者冲突，返回false
	}
	return true;
}
void init() //初始化，找出所有没有相邻 1 的状态，
{
    tol = 0;  //记录合法的状态数
    for(int st=0;st < (1<<m);st++){
        if(!check1(st)) v[tol++]=st;  //将所有没有相邻 1 的状态存入数组 v[] 中
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    //从第 0 行第 0 列开始
    for(int i=0;i<n;i++){  
        for(int j=0;j<m;j++){
			scanf("%d",&f[i][j]);
		}
    }
    init();
	for(int i=0;i<tol;i++){  //初始化第 0 行，也就是首行
		if(check2(0,v[i]))   //如果当前行与当前行的状态不冲突
            dp[0][v[i]] = 1;
	}
    for(int i=1;i<n;i++){  //逐行 dp
		for(int j=0;j<tol;j++){  //遍历当前行所有可能的状态
			if(!check2(i,v[j])) continue;  //如果当前行与当前行的状态冲突，则返回处理下一个状态
			for(int k=0;k<tol;k++){      //遍历上一行即 i-1 行的所有状态
                if(!check2(i-1,v[k])) continue; //判断 i-1 行与其所处状态 v[k] 是否冲突  此条件可有可无，因为如果 i-1 行与其所处状态 v[k] 冲突的话 dp[i-1][v[k]]=0 对结果不影响的
				if((v[j] & v[k])==0){   //如果当前第 i 行的状态 v[j] 与其前一行状态 v[k] 不冲突的话，即不存在二者有一位同时为 1 的情况 
					dp[i][v[j]] = (dp[i][v[j]] + dp[i-1][v[k]])%mod;
				}
			}
		}
	}


    int ans = 0;
    for(int i=0;i<tol;i++) ans = (ans+dp[n-1][v[i]])%mod;
    printf("%d\n",ans);
    return 0;
}
/*
Sample Input
2 3
1 1 1
0 1 0
Sample Output
9
*/