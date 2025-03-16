// HDU 1394
//https://www.cnblogs.com/-Unc/p/4111728.html  题解
// 在一个排列中，如果一对数的前后位置与大小顺序相反，即前面的数大于后面的数，那么它们就称为一个逆序。
//一个排列中逆序的总数就称为这个排列的逆序数。逆序数为偶数的排列称为偶排列；逆序数为奇数的排列称为奇排列。
//如2431中，21，43，41，31是逆序，逆序数是4，为偶排列。
// 也是就说，对于n个不同的元素，先规定各元素之间有一个标准次序（例如n个 不同的自然数，可规定从小到大为标准次序），
//于是在这n个元素的任一排列中，当某两个元素的先后次序与标准次序不同时，就说有1个逆序。一个排列中所有逆序总数叫做这个排列的逆序数。
// 如：0 3 4 1 2

// 设逆序数初始n = 0；

// 由于0后面没有比它小的，n = 0

// 3后面有1,2 n = 2

// 4后面有1,2,n = 2

// 所以该序列逆序数为 n=2+2=4

// 其根据题意移动产生的序列有(每次将第一个字母移到最后一个)

// 3 4 1 2 0   逆序数：8

// 4 1 2 0 3  逆序数：6

// 1 2 0 3 4  逆序数：2

// 2 0 3 4 1  逆序数：4

// 所以最小逆序数为2

// 这里有一个求最小逆序数的规律，只要知道初始序列的逆序数就能够递推比较得出最小逆序数

// 引用上面的例子

// 3 4 1 2 0   逆序数：8

// 4 1 2 0 3  逆序数：6

// 3后面比3小的数有1,2,0，所以逆序对为t=3，比3大的数只有4，所以顺序对为1，即顺序对=n-1-t,n表示序列中数字的总个数，当3移到最后一位时，逆序对转化成顺序对，

// 所以原来的逆序数k要减去对于该数的原来的逆序对，而顺序对转化成逆序对，所以要加上

// 归纳总结得到   现在的逆序数=k+(n-1-t)-t=k+n-2t-1

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
const int N = 5e3+5;
int n;
int tree[N<<2];
int a[N];
void pushUp(int rt)
{
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l == r){
        tree[rt] = 0;
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushUp(rt);
}
void update(int l,int r,int pos,int rt)
{
    if(l == r){
        tree[rt]++;
        return;
    }
    int mid = (l+r)>>1;
    if(pos <= mid)
        update(l,mid,pos,rt<<1);
    else    
        update(mid+1,r,pos,rt<<1|1);
    pushUp(rt);
}
int query(int l,int r,int x,int y,int rt)
{
    if(x<=l && r<=y) return tree[rt];
    int mid = (l+r)>>1;
    int ans = 0;
    if(x <= mid)
        ans += query(l,mid,x,y,rt<<1);
    if(y > mid)
        ans += query(mid+1,r,x,y,rt<<1|1);
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        build(0,n-1,1);
        int sum = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum += query(0,n-1,a[i],n-1,1);//求出初始字符串的逆序数，这里也可以用暴力搜索出初始然后递推
            update(0,n-1,a[i],1);
        }
        int ret = sum;
        for(int i=0;i<n-1;i++){ //这里只要执行n-1次就行了
            sum += (n-1-a[i])-a[i]; //以a[i]开头的字符串，这里是从0到n-1，所以a[i]后面有a[i]个比他小的，根据递推公式即可得出
            ret = min(ret,sum);
        }
        printf("%d\n",ret);
    }
    return 0;
}
/*
Sample Input
10
1 3 6 9 0 8 5 7 4 2
Sample Output
16
*/