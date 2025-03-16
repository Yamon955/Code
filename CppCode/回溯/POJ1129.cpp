#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int map[30][30];
int vis[30];
int best;
int check(int x,int color)
{
    for(int i=0;i<x;i++){
        if(map[i][x]==1&&vis[i]==color) return 0;
    }
    return true;
}
void dfs(int x,int sum)
{
    if(sum>best) return;
    if(x>=n){
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,vis[i]);
        }
        if(ans<best) best = ans;
        return;
    }
    int flag=0;
    for(int i=1;i<=sum;i++){
        if(check(x,i)){
            vis[x] = i;
            dfs(x+1,sum);
            vis[x] = 0;
            flag = 1;
        }
    }
    if(flag==0) {
        vis[x] = sum+1;
        dfs(x+1,sum+1);
        vis[x] = 0;
    }


}
int main()
{
    while(1){
        cin>>n;
        if(n==0) break;
        else {
            memset(map,0,sizeof(map));
            memset(vis,0,sizeof(vis));
            best = 0x3f3f3f3f;
            for(int i=1;i<=n;i++){
                string s;
                cin>>s;
                int a = s[0]-'A';
                int b = s.size();
                for(int i=2;i<b;i++){
                    int c = s[i]-'A';
                    map[a][c] = 1;
                    map[c][a] = 1;
                } 
            }
            //vis[0] = 1;
            dfs(0,0);
            if(best==1) cout<<best<<" channel needed."<<endl;
            else        cout<<best<<" channels needed."<<endl;
        }
    }
    return 0;
}
/*
Sample Input
2
A:
B:
4
A:BC
B:ACD
C:ABD
D:BC
4
A:BCD
B:ACD
C:ABD
D:ABC
0
Sample Output
1 channel needed.
3 channels needed.
4 channels needed. 
*/