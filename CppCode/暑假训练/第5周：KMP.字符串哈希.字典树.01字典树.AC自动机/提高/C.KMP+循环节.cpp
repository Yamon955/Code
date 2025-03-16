//HDU 1358
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
const int N = 1e6+5;
int n;
char s[N];
int Next[N];
int cnt;
void getNext(char *s)
{
    mem(Next,0);
    Next[0] = -1;
    int len = strlen(s);
    int j = 0;
    int k = -1;
    while(j < len){
        if(k==-1 || s[j]==s[k]){
            j++;
            k++;
            Next[j] = k;
        }
        else k = Next[k];
    }
}
int main()
{
    int Case = 0;
    while(scanf("%d",&n)!=EOF){
        if(n == 0) break;
        scanf("%s",s);
        getNext(s);
        printf("Test case #%d\n",++Case);
        for(int i=1;i<=n;i++){
            int num = i-Next[i];        //s[0] ~ s[i] 前缀字符串的循环节大小
            if(i%num==0 && i/num > 1){  //如果循环节的个数大于 1，并且每个循环节都是完整的
                printf("%d %d\n",i,i/num);
            }
        }
        printf("\n");
    }
    return 0;
}
/*
Sample Input
3
aaa
12
aabaabaabaab
0
Sample Output
Test case #1
2 2
3 3

Test case #2
2 2
6 2
9 3
12 4
*/