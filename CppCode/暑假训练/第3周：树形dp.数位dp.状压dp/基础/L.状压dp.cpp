//洛谷P1896
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
const int N = 15;
int n,k;
ll dp[9][1<<9][85];
// dp[i][st][j] 表示我们已经放了(0~i) 行,用了j个国王,当前第i行的状态为s的方案数
bool check1(int st)  //判断单行状态st合法，即该状态二进制表示不存在相邻的 1
{
    for(int j = 0; j < n; j++){
        if(st & (1<<j) ){  //如果当前第 j 位为 1
            if(j+1<n && (st & (1<<(j+1))) ) //并且如果第 j+1 位也为 1，意味着当前状态两个国王相邻了，不合法，返回false
                                          // 注意要保证 j+1 < n
                return false; 
        }
    }
    return true;  //如果当前状态合法，返回true
}

bool check2(int now_st,int pre_st)  //判断当前行状态 now_st 与上一行的状态 pre_st 是否冲突
{
    for(int j=0;j<n;j++){  //遍历状态的每一位
        if(now_st & (1<<j) ){  //如果当前状态的第 j 位为 1 ---->就意味着上一行状态 pre_st 的第 j-1 ,j ,j+1 三个位置都不能为 1
            if(pre_st & (1<<(j-1)) ) return false;
            else if(pre_st & (1<<j) ) return false;
            else if(j+1<n && (pre_st & (1<<(j+1)) )) return false;
        }
    }
    return true; //如果当前行状态和上一行状态不冲突，返回true
}
int getNum(int st)  //获取状态 x 中二进制表示中所含 1 的个数
{
    int num = 0;
    while(st){
        if(st%2) num++;
        st/=2;
    }
    return num;
}
int main()
{
    scanf("%d%d",&n,&k);
    int tol = (1<<n) -1; //一共的状态数为 0 ~ (1<<k)-1

    for(int i=0;i<n;i++){     //按行dp
        for(int st=0;st<=tol;st++){    //遍历当前行的每一种状态 st
            if(!check1(st)) continue;  //如果当前行 单行状态就不合法(即存在相邻国王) 就处理下一个状态
            if(i==0)  dp[i][st][getNum(st)] = 1;  //如果当前行为第 0 行，第 0 行没有上一行因此只需满足 单行 要求即可
            else{   //如果不是第 0 行的话
                for(int j = getNum(st); j<=k;j++){   //遍历剩下的行要满足的国王数量
                    for(int st2=0;st2<=tol;st2++){   //遍历当前行的前一行的状态 st2
                        if(check1(st2) && check2(st,st2))  //如果前一行状态 st2 满足单行要求，并且当前行状态 st 与 st2 不冲突
                            dp[i][st][j] += dp[i-1][st2][j-getNum(st)];  //则当前行的方案数 += 上一行状态为st2用掉 j-getNum(st) 个国王的方案数
                    }
                }
            }

        }
    }
    ll ans = 0;
    for(int st=0;st<=tol;st++) ans += dp[n-1][st][k];
    printf("%lld\n",ans);
    return 0;
}


