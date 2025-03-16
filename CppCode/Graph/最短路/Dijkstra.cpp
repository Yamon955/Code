#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
const int n=5;
int edge[n+1][n+1];
int S[n+1];
int Path_short[n+1];
int Path[n+1];
int get_min(int l,int r,int& num)
{
    int min=1e9;
    for(int i=l;i<=r;i++){
        if(min>Path[i]) {
            min=Path[i];
            num=i;
        }
    }
    return min;
}
void Dijkstra(int x)
{
    S[x]=1;
    Path_short[x]=0;
    for(int i=2;i<=n;i++){
        int num;
        int min=get_min(2,n,num);
        S[num]=1;
        Path_short[num]=min;
        Path[num]=1e9;
            for(int j=1;j<=n;j++){
                 if(S[j]==0 && Path_short[num]+edge[num][j]<Path[j])
                     Path[j]=Path_short[num]+edge[num][j];
            }
    }
}
int main()
{
    int e;
    cout<<"输入边的条数:"<<endl;
    cin>>e;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) edge[i][j]=1e9;
    for(int i=1;i<=e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a][b]=c;//从顶点a到b的距离为c
        edge[b][a]=c;
    }
    for(int i=2;i<=n;i++){
        Path[i]=edge[1][i];
    }
    Dijkstra(1);
    for(int i=1;i<=n;i++) cout<<Path_short[i]<<endl;
    return 0;
}
/*
7
1 2 2
1 5 9
2 4 6
2 3 18
2 5 1
3 4 2
3 5 4
-->
*/
