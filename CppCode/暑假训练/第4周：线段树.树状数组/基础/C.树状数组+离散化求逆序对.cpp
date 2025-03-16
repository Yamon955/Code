//POJ 2299
//https://www.programminghunter.com/article/7585162583/  题解
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e5+5;
int n;
int tree[N],b[N];
struct node{
    int x,idx;
    bool operator < (const node &a)const{
        if(x == a.x) return idx < a.idx;
        else return x < a.x;
    }
        //从小到大排序,如果x相等，那么编号小的排在前面
       //这是因为这样的话之后离散化的时候，编号小的离散化的数字也是小的
       //之后求逆序对时需要按照原来idx顺序一个一个放离散化的数字
       //相同的x最开始放入的值是小的，后面放入的值是大的，这样不会额外增加逆序对
        //比如一个数组2 2 2 2 按照上述方法离散化成1 2 3 4，逆序对为0。
        //如果离散化成4 3 2 1，则逆序对就会求错了
}a[N];
int lowbit(int x)
{
    return x & (-x);
}
void update(int pos,int x)
{
    for(int i=pos;i<=n;i+=lowbit(i)){
        tree[i] += x;
    }
}
ll Query(int pos)
{
    ll ans = 0;
    for(int i=pos;i;i-=lowbit(i)){
        ans += tree[i];
    }
    return ans;
}
int main()
{
    while(cin>>n && n){
        mem(tree,0); //别忘了初始化
        mem(a,0);
        mem(b,0);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].x);
            a[i].idx = i;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            b[a[i].idx] = i;  //离散化操作，根据原来的idx，进行大小的编号，从小到大编号1-n
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            update(b[i],1);    //将b[i]加入树状数组中
            ans += Query(n) - Query(b[i]);  //求出 b[i]+1 ~ n 的区间和，此值就是a[j].idx==i 所对应的值 a[j].x 的逆序对个数
        }
        cout<<ans<<endl;
    }
}
/*
Sample Input
5
9
1
0
5
4
3
1
2
3
0
Sample Output
6
0
*/