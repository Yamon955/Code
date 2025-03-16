//BZOJ 1821
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int n,k;
typedef struct node{
    int x,y;
}Node;
Node p[1005];
typedef struct edge{
    int u,v;
    double w;
}Edge;
Edge e[1005*1005];
int cnt;//边的条数
int f[1005];
double getlen(Node a,Node b){
    double len = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return len;
}
bool cmp(Edge a,Edge b){
    return a.w < b.w;
}
int find(int x)
{
    if(f[x]!=x) f[x] = find(f[x]);
    return f[x];
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            e[cnt].u = i;
            e[cnt].v = j;
            e[cnt].w = getlen(p[i],p[j]);
            cnt++;
        }
    }
    sort(e,e+cnt,cmp);
    for(int i=1;i<=n;i++) f[i] = i;//并查集初始化
    int count=0;//记录合并的次数，最后要剩下k个不连通的部落，故只需要合并 n-k 次
    double MinLen;//记录最近的两个部落之间的距离
    for(int i=0;i<cnt;i++){
        if(count < n-k){
            if(find(f[e[i].u]) != find(e[i].v)){
                f[find(e[i].u)] = find(e[i].v);
                count++;
            }
        }
        else{
            if(find(f[e[i].u]) != find(e[i].v)){ 
                MinLen = e[i].w;
                break;
            }
        }
    }
    printf("%.2lf",MinLen);
    return 0;
}
/*
Sample Input
4 2
0 0
0 1
1 1
1 0


Sample Output
1.00
*/