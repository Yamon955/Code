//CF 852G
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e6+5;
int n,m;
char s[55];
int trie[N][6],tot,isw[N];
int cnt = 0;
int vis[N];
int tmp;
void init()
{
    mem(trie,0);
    mem(isw,0);
    tot = 1;
}
void insert(char *s)
{
    int pre = 0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        int v = s[i] - 'a';
        if(!trie[pre][v]){
            trie[pre][v] = tot++;
        }
        pre = trie[pre][v];
    }
    isw[pre]++;

}
void find(char *p,int pre)
{
    if(!*p){
        if(isw[pre] && vis[pre]!=tmp){
            cnt += isw[pre];
            vis[pre] = tmp;
        } 
        return;
    }
    if(p[0] == '?'){
        find(p+1,pre);
        for(int i=0;i<5;i++){
            if(trie[pre][i]) find(p+1,trie[pre][i]);
        }
    }
    else {
        int to = p[0] - 'a';
        if(trie[pre][to]) find(p+1,trie[pre][to]);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        insert(s);
    }
    for(int i=1;i<=m;i++){
        scanf("%s",s);
        cnt = 0;
        tmp = i;
        //mem(vis,0); 这里可能会超时
        find(s,0);
        printf("%d\n",cnt);
    }
    return 0;
}
/*
Input
3 1
abc
aec
ac
a?c
Output
3
*/
 