//https://blog.csdn.net/nobleman__/article/details/79491324


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
int trie[N][26];  //字典树
int cnt[N]; //统计包含某个结点的字符串的个数    ->CF--706D   HDU--1251
int tot;
int isw[N];
void init()
{
    mem(trie,0);
    mem(cnt,0);
    mem(isw,0);
    tot = 1;  //这里为了避免出错尽量初始化为 1
}
void insert(char *s)
{
    int len = strlen(s);
    int pre = 0;
    for(int i=0;i<len;i++){
        int c = s[i]-'a';
        if(trie[pre][c]==0){  //不存在该节点，则新建节点 
            trie[pre][c] = tot++;
        }
        pre = trie[pre][c];   //向下走，走到目前搜到的最后一个节点 
        cnt[pre]++; //包含该节点的单词数加 1
    }
    isw[pre] ++;  //字符串结束标志，表示当前节点是某一个字符串的结束(即是某一个字符串的最后一个字符)
                  //这里不能说 isw[pre] = 1   因为可能会有重复的单词
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
    //return cnt[pre];  //返回包含前缀 ptr 的字符串的个数
    
    return isw[pre]==1;  //返回该字典树是否具有完整的字符串 ptr ，如果有则返回 true

}