//CF 706D
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
const int N = 2e5+5;
int T,n,m;
ll a[N];
int cnt[32*N];
ll val[32*N];      //点的值
int ch[32*N][2];   //边的值
int tol;           //节点个数
void init()   //初始化
{
    tol = 1;
    mem(val,0);
    mem(ch,0);
    mem(cnt,0);
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
        cnt[pre]++;  //经过当前结点的数字加 1
    }
    val[pre] = x;    //节点值为 x，即到此是一个数
}
void Delete(ll x)
{
    int pre = 0;
    for(int i=32;i>=0;i--){
        int v = (x>>i)&1;
        pre = ch[pre][v];
        cnt[pre]--;  //经过当前结点的数字加 1
    }
}
ll query(ll x)     //查询所有数中与 x 异或结果最大的数 
{
    int pre = 0;
    for(int i=32;i>=0;i--){
        int v = (x>>i)&1;  //提取x的二进制的第i位
    
        //利用贪心策略，优先寻找和当前位不同的数 
        if(ch[pre][v^1] && cnt[ch[pre][v^1]]) 
            pre = ch[pre][v^1];
        else pre = ch[pre][v];
    }
    return val[pre]; //返回结果
}
int main()
{
    init();
    scanf("%d",&n);
    insert(0);
    while(n--){
        char op[5];
        ll x;
        scanf("%s%lld",op,&x);
        if(op[0] == '+'){
            insert(x);
        }
        else if(op[0] == '-'){
            Delete(x);
        }
        else if(op[0] == '?'){
            ll ans = x^query(x);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
Example
Input
10
+ 8
+ 9
+ 11
+ 6
+ 1
? 3
- 8
? 3
? 8
? 11
Output
11
10
14
13
*/
