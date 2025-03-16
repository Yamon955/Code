//https://blog.csdn.net/zuzhiang/article/details/79872805
// 1. 01字典树是一棵最多 32层的二叉树，其每个节点的两条边分别表示二进制的某一位的值为 0 还是为 1. 
//    将某个路径上边的值连起来就得到一个二进制串。

// 2.节点个数为 1 的层（最高层）节点的边对应着二进制串的最高位。

// 3.以上代码中，tree[i] 表示一个节点，tree[i][0] 和 tree[i][1] 表示节点的两条边指向的节点，val[i] 表示节点的值。

// 4.每个节点主要有 4个属性：节点值、节点编号、两条边指向的下一节点的编号。

// 5.节点值 val为 0时表示到当前节点为止不能形成一个数，否则 val[i]=数值。

// 6.可通过贪心的策略来寻找与 x异或结果最大的数，即优先找和 x二进制的未处理的最高位值不同的边对应的点，这样保证结果最大。


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
ll val[32*N];      //点的值
int tree[32*N][2];   //边的值
int tol;           //节点个数
int cnt[32*N];     //统计经过该节点的数字个数
void init()   //初始化
{
    tol = 1;
    mem(val,0);
    mem(tree,0);
    mem(cnt,0);
}
//要从最高位开始枚举，如果高位可以得1，不管后面怎么样得出来的是多少，一定是最大的。
void insert(ll x)  //往 01字典树中插入 x
{
    int pre = 0;
    for(int i=32;i>=0;i--){  //从高位开始
        int v = (x>>i)&1;  //提取x的二进制的第i位
        if(!tree[pre][v]){  //如果节点未被访问过 
            //tree[tol][0] = tree[tol][1] = 0;//将当前节点的边值初始化
            //val[tol] = 0;        //节点值为0，表示到此不是一个数
            tree[pre][v] = tol++;  //边指向的节点编号
        }
        pre = tree[pre][v];  //下一节点 
        cnt[pre] ++;  //经过该节点(拥有包含该结点所在分支前缀)的数字加 1 ----->应用 HDU--1251    CF--706D
    }
    val[pre] = x;    //节点值为 x，即到此是一个数
}

ll query(ll x)   //查询所有数中与 x 异或结果最大的数 
{
    int pre = 0;
    for(int i=32;i>=0;i--){  //从高位开始
        int v = (x>>i)&1;  //提取x的二进制的第i位
    
        //利用贪心策略，优先寻找和当前位不同的数 
        if(tree[pre][v^1]) // //当前位异或之后产生1 
            pre = tree[pre][v^1]; // v^1 实际上就是 !v
        else pre = tree[pre][v];
    }
    return val[pre]; //返回结果
}
ll query_2(ll x)   //查询所有数中与 x 异或结果最大的数 ,并返回二者异或之后的值
{
    int ans = 0;
    int pre = 0;
    for(int i=32;i>=0;i--){  //从高位开始
        int v = (x>>i)&1;  //提取x的二进制的第i位
    
        //利用贪心策略，优先寻找和当前位不同的数 
        if(tree[pre][v^1]){ // //当前位异或之后产生1 
            ans += (1<<i);   //将该位置产生的 1 加入到 ans 中
            pre = tree[pre][v^1]; // v^1 实际上就是 !v
        }
        else pre = tree[pre][v];
    }
    return ans; //返回异或最大值 ---->相当于 return x^val[pre];
}
void Delete(ll x)     //从 01 字典树中删除 x
{
    int pre = 0;
    for(int i=32;i>=0;i--){
        int v = (x>>i)&1;
        pre = tree[pre][v];
        cnt[pre]--;  //经过当前结点的数字加 1
    }
}