//第一周题目链接  https://vjudge.net/contest/449052#problem/F
//单调栈，最小生成树，树的直径，矩阵快速幂


//kruskal算法 -- O(ElogE)


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int n,m,w,ans;
int p[30];
char ch1,ch2;
struct Node{
    int u,v,w;
}Ns[80];
bool cmp(Node a,Node b){
    return a.w<b.w;
}
int find(int x)//并查集
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    while(1){
        ans = 0;
        cin>>n;
        if(n==0) break;
        int cnt = 0;
        for(int i=1;i<=n-1;i++){
            cin>>ch1>>m;
            for(int j=1;j<=m;j++){
                cin>>ch2>>w;
                Ns[cnt].u = ch1 - 'A';
                Ns[cnt].v = ch2 - 'A';
                Ns[cnt].w = w;
                //cout<<Ns[cnt].u<<" "<<Ns[cnt].v<<" "<<Ns[cnt].w<<endl;
                cnt++;
            }
        }
        sort(Ns,Ns+cnt,cmp);
        for(int i=0;i<=29;i++) p[i]=i;
        for(int i=0;i<cnt;i++){
            if(find(p[Ns[i].u])!=find(p[Ns[i].v])) {
                p[find(Ns[i].u)]=find(p[Ns[i].v]);
                ans += Ns[i].w;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
9
A 2 B 12 I 25
B 3 C 10 H 40 I 8
C 2 D 18 G 55
D 1 E 44
E 2 F 60 G 38
F 0
G 1 H 35
H 1 I 35
3
A 2 B 10 C 40
B 1 C 20
0
样本输出
216
30
*/