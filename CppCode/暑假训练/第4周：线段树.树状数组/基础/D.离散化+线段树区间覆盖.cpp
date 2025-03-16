//poj 2528
//https://blog.csdn.net/zezzezzez/article/details/80230026
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
const int N = 1e4+5;
int n;
int vis[N<<3],lazy[N<<4];
int li[N<<2],ri[N<<2],lsh[N<<2];
void pushDown(int rt)//向下标记
{
    if(lazy[rt]!=-1){
        lazy[rt<<1]=lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = -1;//记得父节点打回标记
    }
}
void update(int l,int r,int x,int y,int c,int rt)
{
    if(x<=l && r<=y){
        lazy[rt] = c;
        return;
    }
    pushDown(rt);
    int mid = (l+r)>>1;
    if(y <= mid) update(l,mid,x,y,c,rt<<1);  //如果只在左区间
    else if(x > mid) update(mid+1,r,x,y,c,rt<<1|1);  //如果只在右区间
    else{  //左右区间均有涉及
         update(l,mid,x,mid,c,rt<<1);
         update(mid+1,r,mid+1,y,c,rt<<1|1);
    }
}
int ans = 0;
void Query(int l,int r,int rt)
{
    if(!vis[lazy[rt]] && lazy[rt]!=-1){ //如果贴了海报，并且没有记录过该海报
        ans ++; //海报数 +1
        vis[lazy[rt]] = 1; //标记已经记录看过这张海报
        return;
    }
    if(l == r) return;
    pushDown(rt);
    int mid = (l+r)>>1;
    Query(l,mid,rt<<1);
    Query(mid+1,r,rt<<1|1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mem(lazy,-1);
        mem(vis,0);
        int tot = 0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&li[i],&ri[i]);
            lsh[tot++] = li[i];  //合并
            lsh[tot++] = ri[i];
        }
        sort(lsh,lsh+tot); //对合并后的数组排序
        int len = unique(lsh,lsh+tot)-lsh; //去重
        int tmp = len;
        for(int i=1;i<tmp;i++){
            if(lsh[i]-lsh[i-1]>1){
                lsh[len++] = lsh[i-1]+1;
            }
        }
        sort(lsh,lsh+len);
        for(int i=0;i<n;i++){
            int x = lower_bound(lsh,lsh+len,li[i])-lsh;
            int y = lower_bound(lsh,lsh+len,ri[i])-lsh;
            update(0,len-1,x,y,i,1);//把线段当做点来处理，而不是线段的端点
        }
        ans = 0;
        Query(0,len-1,1);
        cout<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
1
5
1 4
2 6
8 10
3 4
7 10
Sample Output
4
*/