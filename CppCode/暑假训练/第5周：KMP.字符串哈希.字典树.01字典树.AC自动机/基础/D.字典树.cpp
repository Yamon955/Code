//HDU 2072
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
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
const int N = 1e5+5;
int trie[N][26];
int isw[N];
int tot;
int cnt;
void insert(char *s)
{
    int len = strlen(s);
    int pre = 0;
    for(int i=0;i<len;i++){
        int c = s[i]-'a';
        if(trie[pre][c]==-1){
            trie[pre][c] = ++tot;
        }
        pre = trie[pre][c];
    }
    if(isw[pre]==0) cnt++;
    isw[pre] = 1;
}
void init()
{
    mem(trie,-1);
    mem(isw,0);
    tot = 0;
    cnt = 0;
}
int main(){
    string tmp;
    while(getline(cin,tmp) && tmp!="#"){
        init();
        stringstream s(tmp);
        char ptr[150];
        //这道题要考虑前面有N个空格，中间有N个空格，后面也有N个空格....然后就是输入空格....
        while(s >> ptr){
            insert(ptr);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
Sample Input
you are my friend
#
Sample Output
4
*/