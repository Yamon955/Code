#include<iostream>
using namespace std;
int n,m;
int p[10010];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++) p[i]=i;
    while(m--){
        int z,a,b;
        cin>>z>>a>>b;
        if(z==1){
            p[find(a)]=find(b);
        }
        else if(z==2){
            if(find(a)==find(b)) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}
