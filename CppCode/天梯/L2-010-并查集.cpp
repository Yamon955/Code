#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>
#include<cmath> 
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int N = 105;
int n,m,k;
int E[N][N];
int p[N];
int find(int x)
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--){
        int x,y,c;
        cin>>x>>y>>c;
        if(c==1){
            if(find(x)!=find(y)){
                p[find(x)] = find(y);
            }
        }
        else{
            E[x][y] = 1;
            E[y][x] = 1;
        }
    }
    while(k--){
        int x,y;
        cin>>x>>y;
        if(find(x) == find(y) && E[x][y] == 0){
            cout<<"No problem"<<endl;
        }
        else if(find(x)!=find(y) && E[x][y] == 0){
            cout<<"OK"<<endl;
        }
        else if(E[x][y] == 1){
            if(find(x) == find(y)) cout<<"OK but..."<<endl;
            else cout<<"No way"<<endl;
        }
    }
}
/*
输入样例：
7 8 4
5 6 1
2 7 -1
1 3 1
3 4 1
6 7 -1
1 2 1
1 4 1
2 3 -1
3 4
5 7
2 3
7 2
结尾无空行
输出样例：
No problem
OK
OK but...
No way
*/