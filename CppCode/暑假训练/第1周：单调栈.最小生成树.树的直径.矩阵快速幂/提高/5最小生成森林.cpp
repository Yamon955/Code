//CodeForces  1245
//最小生成森林
// 思路
// 1.把选每个点的代价转成虚拟原点到这个点的边。这个我第一次遇到，属实妙
// 2.这样做就可以将所有要求的值转化到图中来做了。
// 3.我们要求的就是一个最小生成树，因为最终所有的点要联系在一起

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int n;
int x,y;
int c,k[2005],p[2005];
pair<int ,int>point[2005];
typedef struct node{
    int u,v;
    ll w;
}Edge;
Edge edge[2005*2005];
int cnt;//记录边的条数
ll cost;//记录最小花费
int num_v;//记录单独建立发电站的个数
int idx_v[2005];//记录单独建立发电站的点的编号,如果在 i 点建立发电站 idx_v[i] = 1;
int num_e;//记录建立的边的个数
pair<int,int>idx_e[2005];//记录建立的边的两端
bool cmp(Edge a,Edge b){
    return a.w < b.w;
}
int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x]; 
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        point[i].first = x;
        point[i].second = y;
    }
    for(int i=1;i<=n;i++){
        cin>>c;
        cnt++;
        edge[cnt].u = 0;//特殊点 0
        edge[cnt].v = i;
        edge[cnt].w = c;//特殊点 0 到其他点 j 之间的权值为在该点建立发电站的花费 c[j]
    }
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cnt++;
            edge[cnt].u = i;
            edge[cnt].v = j;  
            edge[cnt].w = (ll)( abs(point[i].first - point[j].first) + abs(point[i].second - point[j].second) ) * (k[i]+k[j]);
            //不强制转化就ac不了
        }
    }
    sort(edge+1,edge+cnt+1,cmp);
    for(int i=0;i<=n;i++) p[i] = i;//并查集初始化 
    for(int i=1;i<=cnt;i++){
        if(find(edge[i].u)!=find(edge[i].v)){ //如果这两点不想连
            p[find(edge[i].u)] = find(edge[i].v);//将两点连起来
            if(edge[i].u==0){  //需要在edge[i].v点建立发电站
                num_v++;
                idx_v[edge[i].v] = 1;
            }
            else{  //需要建立边
                num_e++;
                idx_e[num_e].first = edge[i].u;
                idx_e[num_e].second = edge[i].v;
            }
            cost += edge[i].w;  //加上花费
        }
    }
    cout<<cost<<endl;
    cout<<num_v<<endl;
    for(int i=1;i<=n;i++) 
        if(idx_v[i] == 1)  cout<<i<<" ";
    cout<<endl;
    cout<<num_e<<endl;
    for(int i=1;i<=num_e;i++) cout<<idx_e[i].first<<" "<<idx_e[i].second<<endl;
}
/*
Examples
Input
3
2 3
1 1
3 2
3 2 3
3 2 3
Output
8
3
1 2 3 
0
Input
3
2 1
1 2
3 3
23 2 23
3 2 3
Output
27
1
2 
2
1 2
2 3
*/