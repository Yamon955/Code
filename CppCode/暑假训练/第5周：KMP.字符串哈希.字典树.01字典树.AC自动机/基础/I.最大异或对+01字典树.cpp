//AcWing 143
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
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int T,n,m;
ll a[N];
ll val[32*N];      //点的值
int ch[32*N][2];   //边的值
int tol;           //节点个数
void init()   //初始化
{
    tol = 1;
    mem(val,0);
    mem(ch,0);
}
void insert(ll x)  //往 01字典树中插入 x
{
    int pre = 0;
    for(int i=32;i>=0;i--){
        int v = (x>>i)&1;
        if(!ch[pre][v]){  //如果节点未被访问过 
            ch[pre][v] = tol++;  //边指向的节点编号
        }
        pre = ch[pre][v];  //下一节点 
    }
    val[pre] = x;    //节点值为 x，即到此是一个数
}

ll query(ll x)     //查询所有数中与 x 异或结果最大的数 
{
    int pre = 0;
    for(int i=32;i>=0;i--){
        int v = (x>>i)&1;  //提取x的二进制的第i位
    
        //利用贪心策略，优先寻找和当前位不同的数 
        if(ch[pre][v^1]) 
            pre = ch[pre][v^1];
        else pre = ch[pre][v];
    }
    return val[pre]; //返回结果
}
ll query_2(ll x)  //直接求出 x 与异或结果最大的数的异或值
{
    int ans = 0;  //记录最大异或值
    int pre = 0;
    for(int i=32;i>=0;i--){
        int v = (x>>i)&1;  //提取x的二进制的第i位
        if(ch[pre][v^1]){  //当前位异或之后产生1 
            ans += (1<<i);  //异或之后的值
            pre = ch[pre][v^1];
        }
        else pre = ch[pre][v];
    }
    return ans;  //直接返回最大异或值
}
int main()
{
    scanf("%d",&n);
    init();
    ll Max = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        insert(a[i]);
        // ll ans = a[i] ^ (query(a[i]));
        // Max = max(Max,ans);
        Max = max(Max,query_2(a[i]));
    }
    printf("%d",Max);
    return 0;
}
/*
Sample Input
5
2 9 5 7 
Sample Output
14
*/
