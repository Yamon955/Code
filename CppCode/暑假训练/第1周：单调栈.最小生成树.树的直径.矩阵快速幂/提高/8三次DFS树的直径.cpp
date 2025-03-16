//CodeForces 1294F

//3次dfs
//第一次dfs找出距离 1(任意选，那个点都行) 最远的点 x
//第二次dfs从 x 出发找出距离 x 最远的点 y,并且用dis2[]数组记录下其他点到点 x 的距离
//第三次dfs从 y 出发 用数组dis3[]记录下其他点到点 y 的距离
//x , y 就是相距最远的两个点
//只要点 i 满足 dis2[i]+dis3[i]最大 即点 i 到x,y的距离之和最大，则点 i 就是 z 点
//最后输出即可

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int n;
vector<int>p[200005];
int dis1[200005],dis2[200005],dis3[200005];
int vis[200005];
int x,y;//相距最远的两点
int z;//距离x,y之和最大的点
void dfs(int idx,int step,int dis[]){
    dis[idx] = step;
    for(int i=0;i<p[idx].size();i++){  //p[idx][i] 表示 点 idx 可以到达的点 及 idx ---> p[idx][i]
        if(vis[p[idx][i]] == 1) continue;
        vis[p[idx][i]] = 1;
        dfs(p[idx][i],step+1,dis);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        p[a].push_back(b); // a--->b
        p[b].push_back(a); // b--->a
    }

    memset(vis,0,sizeof vis);
    vis[1] = 0;
    dfs(1,0,dis1);   //选择任意一个点   从所选点dfs,dis1[]记录其他点到该点的距离
    int Max = 0;
    for(int i=1;i<=n;i++){  //找出距离所选任意点最远的点 x
        if(Max < dis1[i]){
            Max = dis1[i];
            x = i;
        }
    }

    memset(vis,0,sizeof vis);
    vis[x] = 1; 
    dfs(x,0,dis2);  //从点 x 出发dfs  ,dis2[]数组记录其他点到点 x 的距离
    Max = 0;
    for(int i=1;i<=n;i++){  //找出距离点 x 最远的点 y
        if(Max < dis2[i]){
            Max = dis2[i];
            y = i;
        }
    }
    memset(vis,0,sizeof vis);
    vis[y] = 1;
    dfs(y,0,dis3);  //从点 y 出发dfs  ,dis3[]数组记录其他点到点 y 的距离
    
    Max = 0;
    for(int i=1;i<=n;i++){
        if(i==x||i==y) continue;
        if(Max < dis2[i]+dis3[i]){   //找出一个点 满足  dis2[i] + dis3[i]最大
            Max = dis2[i]+dis3[i];
            z = i;
        }
    }
    int ans = (Max + dis2[y])/2;
    cout<<ans<<endl;
    cout<<y<<" "<<x<<" "<<z;
    return 0; 

}
