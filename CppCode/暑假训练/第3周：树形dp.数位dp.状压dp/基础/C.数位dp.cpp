//HDU3652
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
int n,len,a[20];
int dp[20][2][2][13];
//只有当前遍历到的位数满足四种状态才可以记忆化返回
//假如一个八位数 ABCD????(后四位不确定，当前正在确定第五位)  --->当前状态表示为dp[5][D==1][(AB==13)||(BC==13)||(CD==13)][(A*1000+B*100+C*10+D)%13]-->假设为dp[5][x][y][z]
//如果前面已经已经算出一个八位数DEFG???? ---->当前状态也为 dp[5][x][y][z];
//如果此状态与ABCD????一样，则ABCD????就不用计算直接返回 DEFG???? dp状态即可
//只有当两个状态完全一样并且二者当前位置选数都没有限制即limit==0
//代码体现为  if(!limit && dp[pos][pre][st][mod]!=-1) return dp[pos][pre][st][mod];


//dp[pos][pre][st][mod]  pos-->第几位，pre-->当前位前一位数字是不是1，st-->当前位之前是不是已经包含了13，mod-->对13的余数
int dfs(int pos,int pre,int st,int mod,int limit)
{
    if(pos > len) return(st && mod==0);
    if(!limit && dp[pos][pre][st][mod]!=-1) return dp[pos][pre][st][mod];
    int ans = 0;
    int up = limit?a[len-pos+1]:9;
    for(int i=0;i<=up;i++){
        if(pre && i==3) ans += dfs(pos+1,i==1,1,(mod*10+i)%13,(i==up)&&limit);
        else ans += dfs(pos+1,i==1,st?1:0,(mod*10+i)%13,(i==up)&&limit);
    }
    if(!limit) dp[pos][pre][st][mod] = ans;
    return ans;
}
int part(int x)
{
    len = 0;
    memset(dp,-1,sizeof dp);
    while(x){
        a[++len] = x%10;
        x/=10;
    }
    return dfs(1,0,0,0,1);
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",part(n));
    }
    return 0;
}