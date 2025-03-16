//SPOJ - BALNUM
//用一个三进制表示每个数字出现的状态，1表示出现过奇数次，0表示从未出现过，1表示出现过偶数次。dp[l][s]长度为i,s代表当前状态。
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
const int N = 30;
int T,len,a[N];  
ll l,r;
ll dp[N][60000];  // 3^10=59049
int get_newst(int st,int x)  // st 按三进制处理，x:0~9
{
    int num[10];
    for(int i=0;i<=9;i++){  // st 按三进制处理
        num[i] = st%3;
        st /= 3;
    }
    //num[i]==0 代表数字 i 出现 0 次
    //num[i]==1 代表数字 i 出现 奇数 次
    //num[i]==2 代表数字 i 出现 偶数 次
    if(num[x]==0) num[x] = 1;  //如果原来 x 没有出现过，则置 num[x] = 1,表示 x 出现 奇数次
    else if(num[x]==1) num[x] = 2;  //如果原来 x 出现 奇数 次，则置 num[x] = 2,表示 x 出现 偶数 次
    else if(num[x]==2) num[x] = 1;  //如果原来 x 出现 偶数 次，则置 num[x] = 1,表示 x 出现 奇数 次
    int newst = 0;
    for(int i=9;i>=0;i--){
        newst *= 3;
        newst += num[i];
    }
    return newst;  //形成新的状态
}
bool check(int st)  //判断此状态是否合法
{
    int num[10];
    for(int i=0;i<=9;i++){
        num[i] = st%3;
        st /= 3;
    }
    for(int i=0;i<=9;i++){
        if(num[i]!=0){  //如果数字 i 出现过
            if(i%2==0&&num[i]==2) return false;  //如果数字 i 为偶数出现偶数次，返回 false
            if(i%2==1&&num[i]==1) return false;  //如果数字 i 为奇数出现奇数次，返回 false
        }
    }
    return true;
}
ll dfs(int pos,int st,int lead,int limit)  //st 用三进制表示每个数字的出现次数如何，如 st=6-->三进制表示为 10 表示数字 1 出现奇数次
{                                                                        //st=7-->三进制表示为 21 表示数字 1 出现偶数次，数字 0 出现 奇数次
   if(pos==0){
       if(check(st)) return 1;
       else return 0;
   }
   if(!limit && !lead && dp[pos][st]!=-1) return dp[pos][st];
   ll ans = 0;
   int up = limit?a[pos]:9;
   for(int i=0;i<=up;i++){
       if(lead && i==0) ans += dfs(pos-1,st,lead,(i==up)&&limit);
       else ans += dfs(pos-1,get_newst(st,i),0,(i==up)&&limit);
   }
   if(!lead && !limit) dp[pos][st] = ans;
   return ans;
}
ll part(ll x)
{
    len = 0;
    while(x){
        a[++len] = x%10;
        x /= 10;
    }
    return dfs(len,0,1,1);
}
int main()
{
    cin>>T;
    memset(dp,-1,sizeof dp);
    while(T--){
        cin>>l>>r;
        cout<<part(r)-part(l-1)<<endl;
    }
    return 0;
}
/*
Input:
2
1 1000
1 9
Output:
147
4
*/
