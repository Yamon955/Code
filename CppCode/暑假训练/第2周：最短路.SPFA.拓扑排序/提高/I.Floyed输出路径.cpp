//HDU1385
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 105;
int n;
int map[N][N],b[N],path[N][N];
void Floyed()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) path[i][j] = j;  //Floyed()求最短路径，path[][]一定要初始化
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][j] > map[i][k]+map[k][j]){
                    map[i][j] = map[i][k]+map[k][j];
                    path[i][j] = path[i][k];
                }
                else if(map[i][j] == map[i][k]+map[k][j]){
                    path[i][j] = min(path[i][j],path[i][k]);  //如果路径相等，选择走字典序最小的
                } 
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==-1)
                    map[i][j] = inf;
            }
        }
        for(int i=1;i<=n;i++) {
            scanf("%d",&b[i]);
            for(int j=1;j<=n;j++){
                if(map[j][i]<inf) map[j][i]+=b[i];  //将每个城市的税加入到指向该城市的单向边的权值中
            }
        }
        Floyed();
        int u,v;
        while(cin>>u>>v){
            if(u==-1 && v==-1) break;
            printf("From %d to %d :\n",u,v);
            printf("Path: %d",u);
            int st = u,end = v;
            while(st != end){
                printf("-->%d",path[st][end]);
                st = path[st][end];
            }
            printf("\nTotal cost : %d\n\n",map[u][v]-b[v]);  //最后要减去终点的税
        }
    }
    return 0;
}
/*
Sample Input
5
0 3 22 -1 4
3 0 5 -1 -1
22 5 0 9 20
-1 -1 9 0 4
4 -1 20 4 0
5 17 8 3 1
1 3
3 5
2 4
-1 -1
0
Sample Output
From 1 to 3 :
Path: 1-->5-->4-->3
Total cost : 21

From 3 to 5 :
Path: 3-->4-->5
Total cost : 16

From 2 to 4 :
Path: 2-->1-->5-->4
Total cost : 17
*/