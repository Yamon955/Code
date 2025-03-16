//HDU2112
#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 155; 
int n;
string st,en;
int f[N][N],len,dis[N],vis[N];
map<string,int>Map;
priority_queue< pair<int,int> >q;
void Dijstra(string s)
{
    while(!q.empty()) q.pop();
    dis[Map[s]]=0;
    q.push({0,Map[s]});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i=1;i<=len;i++){
            if(dis[i]>dis[u]+f[u][i]){
                dis[i] = dis[u]+f[u][i];
                q.push({-dis[i],i});
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        if(n==-1) break;
        memset(f,0x3f,sizeof f);
        Map.clear();
        cin>>st>>en;
        len = 0;
        Map[st] = ++len;
        Map[en] = ++len;
        for(int i=1;i<=n;i++){
            string s1,s2;
            int t;
            cin>>s1>>s2>>t;
            if(!Map[s1]) Map[s1] = ++len;
            if(!Map[s2]) Map[s2] = ++len;
            f[Map[s1]][Map[s2]] = f[Map[s2]][Map[s1]] = min(f[Map[s1]][Map[s2]],t);
        }
        memset(vis,0,sizeof vis);
        memset(dis,0x3f,sizeof dis);
        Dijstra(st);
        if(dis[Map[en]]<inf) cout<<dis[Map[en]]<<endl;
        else cout<<"-1"<<endl;
    }


	return 0;
}
/*
Sample Input
6
xiasha westlake
xiasha station 60
xiasha ShoppingCenterofHangZhou 30
station westlake 20
ShoppingCenterofHangZhou supermarket 10
xiasha supermarket 50
supermarket westlake 10
-1
Sample Output
50
*/