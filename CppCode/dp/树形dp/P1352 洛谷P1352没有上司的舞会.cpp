/*
f[x][0]表示以x为根的子树,且x不参加舞会的最大快乐值

f[x][1]表示以x为根的子树，且x参加了舞会的最大快乐值

则f[x][0]=sum{max(f[y][0],f[y][1])} (y是x的儿子)

f[x][1]=sum{f[y][0]}+h[x] (y是x的儿子)

先找到唯一的树根root

则ans=max(f[root][0],f[root][1])
*/
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
int n,m;
vector<int>v[N];
int w[N],vis[N],root;
int f[N][2];
void dfs(int x)
{
    f[x][0] = 0;
    f[x][1] = w[x];
    for(auto y:v[x]){
        dfs(y);
        f[x][0] += max(f[y][0],f[y][1]);
        f[x][1] += f[y][0];
    } 
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n-1;i++){
        int l,k;
        scanf("%d%d",&l,&k);
        v[k].push_back(l);
        vis[l] = 1;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            root = i;  //找到根
            break;
        }
    dfs(root);
    printf("%d",max(f[root][0],f[root][1]));  
    return 0;
}
/*
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
---->5
*/