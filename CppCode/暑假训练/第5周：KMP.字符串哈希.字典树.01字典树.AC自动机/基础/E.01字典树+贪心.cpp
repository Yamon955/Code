//HDU 4825
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
            //ch[tol][0] = ch[tol][1] = 0;//将当前节点的边值初始化
            //val[tol] = 0;        //节点值为0，表示到此不是一个数
            ch[pre][v] = tol++;  //边指向的节点编号
        }
        pre = ch[pre][v];  //下一节点 
    }
    val[pre] = x;    //节点值为 x，即到此是一个数
}

ll query(ll x)   //查询所有数中与 x 异或结果最大的数 
{
    int pre = 0;
    for(int i=32;i>=0;i--){
        int v = (x>>i)&1;
    
        //利用贪心策略，优先寻找和当前位不同的数 
        if(ch[pre][v^1]) pre = ch[pre][v^1];
        else pre = ch[pre][v];
    }
    return val[pre]; //返回结果
}
int main()
{
    scanf("%d",&T);
    int Case = 0;
    while(T--){
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            insert(a[i]);
        }
        printf("Case #%d:\n",++Case);
        while(m--){
            ll x;
            scanf("%d",&x);
            ll ans = query(x);
            printf("%lld\n",ans);
        }

    }
    return 0;
}
/*
Sample Input
2
3 2
3 4 5
1
5
4 1
4 6 5 6
3
Sample Output
Case #1:
4
3
Case #2:
4
*/
