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
const int N = 1e6;
int n;
int a[N];
//奇数的结点一定是叶子结点
//数组一定要从1开始
int lowbit(int x) //取出x的最低位1  //如 x=6,二进制 x=110--->返回值为 10(即对应十进制的 2)
                                   //x = 7即x = 111  ---->返回值为 1(即对应十进制 1)   //x = 8即x = 1000 --->返回值为 1000(即对应十进制的 8)
{
    return x & (-x);
}
//单点更新
void update(int pos,int x)  //pos 为更新的位置  x 为增量
{
    for(int i=pos;i<=n;i += lowbit(i)){  //n 为树状数组的长度
        a[pos] += x;
    }
}
//区间查询
int Query(int pos)  // 求出的是 1~pos 的区间和
{
    int ans = 0;
    for(int i=pos; i ;i -= lowbit(i)){
        ans += a[i];
    }
}

int d[N]; //是原数组 a[] 的差分数组 d[1] = a[1],d[2] = a[2]-a[1],d[3] = a[3]-a[2]....  a[1]=d[1],a[2]=d[2]+d[1],a[3]=d[3]+d[2]+d[1];
          //差分数组 d[] 用来实现树状数组的区间更新
