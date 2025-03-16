//CF 432D
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
const int N = 1e6+5;
char s[N];
int Next[N];
int cnt,L[N];
int dp[N];//定义一个dp数组（注意每个都要初始化为1，dp意思为每种前缀出现的次数）
void getNext(char *s)
{
    mem(Next,0);
    Next[0] = -1;
    int j = 0;
    int k = -1;
    int len = strlen(s);
    while(j < len){
        if(k == -1 || s[j] == s[k]){
            j++;
            k++;
            Next[j] = k;
        }
        else k = Next[k];
    }
}

int main()
{
    scanf("%s",s);
    getNext(s);
    int len = strlen(s);
    for(int i=0;i<=len;i++) dp[i] = 1;
    cnt = 0;
    L[cnt++] = len;  //字符串本身也可以视为一种前缀
    for(int i=Next[len];i>=1;i=Next[i]) {  //利用kmp的next数组求出所有满足前后缀的子串序号,存入 L 数组
        L[cnt++] = i;
    }
    for(int i=len;i>=1;i--) 
        dp[Next[i]] += dp[i];  // dp 求每种前缀出现次数
    printf("%d\n",cnt); 
    for(int i=cnt-1;i>=0;i--){
        printf("%d %d\n",L[i],dp[L[i]]);
    }
    return 0;
}
/*
Input
ABACABA
Output
3
1 4
3 2
7 1
Input
AAA
Output
3
1 3
2 2
3 1
*/