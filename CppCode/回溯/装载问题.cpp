#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,c1,c2;
int w[1000];
int vis[1000],best_vis[1000];
int best_w,new_w;
void Backtrack(int i)
{
    if(i>n){
        if(new_w>best_w){
            best_w = new_w;
            for(int i=1;i<=n;i++) best_vis[i] = vis[i];
        }
        return;
    }
    if(new_w+w[i]<=c1){
        new_w += w[i];
        vis[i] = 1;
        Backtrack(i+1);
        new_w -= w[i];
        vis[i] = 0;
    }
    Backtrack(i+1);
}
int main()
{
    cin>>n>>c1>>c2;
    for(int i=1;i<=n;i++) cin>>w[i];
    Backtrack(1);
    if(best_w==0){
        cout<<"no solution";
        return 0;
    }
    cout<<best_w<<endl;
    for(int i=1;i<=n;i++) cout<<best_vis[i]<<" ";
    return 0;
}