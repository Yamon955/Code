#include<iostream>
#include<cstdio>
using namespace std;
int p[1010],Size[1010];
int n,m;
int find(int a)
{
    if(p[a]!=a) p[a]=find(p[a]);
    return p[a];
}
void Union(int a,int b)
{
    p[find(a)]=find(b);
}
int main()
{
    while(1){
        cin>>n;
        if(n==0) break;
        cin>>m;
        for(int i=1;i<=n;i++){
            p[i]=i;
        } 
        while(m--){
            int a,b;
            cin>>a>>b;
            if(find(a)!=find(b)){
                p[find(b)]=find(a);
            }
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if(i==p[i]) count++;//统计指向自身的结点个数，此个数减一即为不连通的连通块数
        }
        cout<<count-1<<endl;
    }
    return 0;
}
/*
Sample Input
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
Sample Output
1
0
2
998
*/