//HDU-3038
//https://www.cnblogs.com/liyinggang/p/5327055.html
//https://blog.csdn.net/Qiuker_jl/article/details/109810989
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<vector>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 2e5+5;
int n,m;
int ans;
/*
如何保存这个信息？对于[a,b]上数之和，将其抽象为边的权值，即端点a和端点b之间的权值，
则对于题目给出的m个[a,b]区间的和，就转化为了森林，端点相接的在同一棵树上（即树链）
为了方便处理，将[a,b]转化为（a,b]。好处是可以将[a,b]和[b+1,c]的端点拼起来
比如：
已知[4,7]上的数之和为5，将这个信息保存为：点3和点7之间有边相连，权值为5
已知[2,3]上的数之和为2，将这个信息保存为：点1和点3之间有边相连，权值为2
则点1和点7间的距离也可得到
*/
struct node{
    int fa;  //p[i].fa 表示 i 的根节点
    int w;   //p[i].w  表示从 i(不包括点 i) 到 根节点p[i].fa 区间之和 即 p[i].w = (i,p[i].fa]区间和 = [i+1,p[i].fa]区间和
};
node p[N];
void init()
{
    for(int i=0;i<=n;i++){
        p[i].fa = i;
        p[i].w = 0;
    }
}
int find(int x)
{
    if(x != p[x].fa){
        int tmp = p[x].fa;
        p[x].fa = find(p[x].fa);
        p[x].w = p[tmp].w + p[x].w;
    }
    return p[x].fa;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        ans = 0;
        int a,b,sum;
        while(m --){
            cin>>a>>b>>sum;
            a--; //（这里的a要说明一下由于是区间 [a,b] ，[a,b] = [root,b]-[root,a-1],所以a要减一）
            int ra = find(a);
            int rb = find(b);
            if(ra != rb){
                p[ra].fa = rb;
                p[ra].w = -p[a].w + sum + p[b].w;
                /*
                    a->b = sum
                    a->ra = p[a].w
                    b->rb = p[b].w
                    ra->rb = ra->a + a->b + b->rb 
                           = -(a->ra) + a->b + b->rb
                */
            }
            else{
                //如果 a 和 b 的根节点相同，假设为 root
                //a->root = p[a].w   b->root = p[b].w
                //所以说之前的 (a,b] 区间和为 a->b = a->root + root->b = a->root - root->b = p[a].w - p[b].w
                //如果现在回答的 (a,b] 的区间和与之前的矛盾 即 p[a].w - p[b].w != sum 则说明当前回答是错误的
                if(p[a].w - p[b].w != sum) ans ++;
            }
        }
        printf("%d\n",ans);
    }
}
/*
Sample Input
10 5
1 10 100
7 10 28
1 3 32
4 6 41
6 6 1
Sample Output
1
*/