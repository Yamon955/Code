#include<iostream>
using namespace std;
int n,m,P;
int p[10010];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m>>P;
    for(int i=0;i<=n;i++) p[i]=i;
    while(m--){
       int a,b;
       cin>>a>>b;
       p[find(a)]=find(b);
    }
    while(P--){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
