//HDU 1251
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
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e5+5;
char s[12],ptr[12];
int trie[N][26];
int cnt[N];
int tot;
void insert(char *s)
{
    int len = strlen(s);
    int pre = 0;
    for(int i=0;i<len;i++){
        int c = s[i]-'a';
        if(trie[pre][c]==0){  //不存在该节点，则新建节点 
            trie[pre][c] = ++tot;
        }
        pre = trie[pre][c];   //向下走，走到目前搜到的最后一个节点 
        cnt[pre]++; //包含该节点的单词数加 1
    }
}
int find(char *ptr)
{
    int len = strlen(ptr);
    int pre = 0;
    for(int i=0;i<len;i++){
        int c = ptr[i]-'a';
        if(trie[pre][c]==0) return 0;  //不存在具有该前缀的字符串 
        pre = trie[pre][c];
    }
    return cnt[pre];
}
void init()
{
    mem(trie,0);
    mem(cnt,0);
    tot = 0;
}
int main()
{
    init();
    while(gets(s)){
        if(strlen(s)==0) break;
        insert(s);
    }
    while(gets(ptr) && ptr!="\0"){
        int ans = find(ptr);
        printf("%d\n",ans);
    }
    return 0;
}
/*
Sample Input
banana
band
bee
absolute
acm

ba
b
band
abc
Sample Output
2
3
1
0
*/
