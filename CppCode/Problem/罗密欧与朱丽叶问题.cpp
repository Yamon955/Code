#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
int sx,sy,ex,ey;
int best=0x3f3f3f3f;
const int dx[8]={0,0,1,-1,1,-1,1,-1};
const int dy[8]={1,-1,0,0,1,1,-1,-1};
int map[100][100];
int best_path[100][100];
int cnt[1000];
void dfs(int x,int y,int step,int pre,int sum)
{
    if(x==ex && y==ey && step==m*n-k){
        if(best>=sum){
            if(best>sum){
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++) 
                        best_path[i][j] = map[i][j];      
            }
            best = sum;
            cnt[best]++;
            
        }
        return ;
    }
    if(step==m*n-k||(x==ex&&y==ey)||sum>best) return ;
    for(int i=0;i<8;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<=0||ny<=0||nx>n||ny>m||map[nx][ny]!=0) continue;
        if(map[nx][ny]==0){
            map[nx][ny]=step+1;
        //     if(pre==-1||pre==i) {
        //         dfs(nx,ny,step+1,i,sum);
        //         map[nx][ny]=0;
        //     }
        //    else {
        //        dfs(nx,ny,step+1,i,sum+1);
        //        map[nx][ny]=0;
        //    } 
            if(pre!=-1&&pre!=i) sum++;
            dfs(nx,ny,step+1,i,sum);
            map[nx][ny]=0;
            if(pre!=-1&&pre!=i) sum--;
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        map[a][b]=-1;
    }
    cin>>sx>>sy>>ex>>ey;
    map[sx][sy]=1;
    dfs(sx,sy,1,-1,0);
    if(best==0x3f3f3f3f) cout<<"No Solution!";
    else {
        cout<<best<<endl;
        cout<<cnt[best]<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cout<<best_path[i][j]<<" ";
            cout<<endl;
        }
            
    }
    return 0;
}
/*
3 4 2
1 2
3 4
1 1
2 2
cout<<:
6
7
1 -1 9 8
2 10 6 7
3 4 5 -1
*/