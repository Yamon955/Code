//POJ2342
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 6e3+5;
int n,m,root;
int f[N][2],vis[N],w[N];
vector<int>v[N];
void dfs(int x)
{
    f[x][0] = 0;   //代表结点 x 不参加舞会
    f[x][1] = w[x];//代表结点 x 参加舞会
    for(int i=0;i<v[x].size();i++){
        int y = v[x][i];
        dfs(y);
        f[x][0] += max(f[y][0],f[y][1]);
        f[x][1] += f[y][0];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    int l,k;
    while(cin>>l>>k){
        if(l==0 && k==0) break;
        v[k].push_back(l);
        vis[l] = 1;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            root = i;
            break;
        }
    dfs(root);
    printf("%d",max(f[root][0],f[root][1]));
    return 0;
}
/*
Sample Input
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
Sample Output
5
*/