//CodeForces 337D

//3次dfs
//第一次dfs找出距离 1(任意选，那个点都行) 最远的感染点 x
//第二次dfs从 x 出发找出距离 x 最远的感染点 y,并且用dis2[]数组记录下其他点到点 x 的距离
//第三次dfs从 y 出发 用数组dis3[]记录下其他点到点 y 的距离
//x , y 就是相距最远的两个感染点
//只要点 i 满足 dis2[i]<=d && dis3[i]<=d及点 i 到x,y的距离都小于等于 d，则点 i 就可以是邪恶之书的所在地 ans++;
//最后输出ans即可
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int n,m,d;
int p[100005];
int vis[100005];
int Max = 0;
vector<int>v[100005];
int dis1[100005],dis2[100005],dis3[100005];
int x,y; //相距最远的两个感染点
void dfs(int idx,int step,int len[])
{
    len[idx] = step;
    for(int i=0;i<v[idx].size();i++){
        if(vis[v[idx][i]]==1) continue;
        vis[v[idx][i]] = 1;
        dfs(v[idx][i],step+1,len);
    }
}
int main()
{
    cin>>n>>m>>d;
    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
        p[a] = 1;
    }
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,0,sizeof vis);
    vis[1] = 1;    //先选出任意一个点
    dfs(1,0,dis1);  //找出距离该点最远的感染点
    int Max=0,x;
    for(int i=1;i<=n;i++){  //遍历找出距离 选的任意点 最远的感染点x
        if(dis1[i]>Max && p[i]==1){
            Max = dis1[i];
            x = i;
        }
    }
    memset(vis,0,sizeof vis);
    vis[x] = 1;
    dfs(x,0,dis2);  //dis2[]  代表每个点到 点x 的距离
    Max = 0;
    for(int i=1;i<=n;i++){  //遍历找出距离 x 最远的感染点 y  则 x,y就是两个相距最远的感染点 因此只要其他没有被感染的点到x,y的距离都小于 d 则该点就有可能是邪恶之书所在地
        if(dis2[i]>Max && p[i]==1){
            Max = dis2[i];
            y = i;
        }
    }
    memset(vis,0,sizeof vis);
    vis[y] = 1;
    dfs(y,0,dis3);  //dis3[]  代表每个点到 点y 的距离
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(dis2[i]<=d && dis3[i]<=d){  ///找出可能的点
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}