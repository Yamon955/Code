//CF 625B
//如果匹配成功，那么最优的贪心策略就是把字符串1中匹配成功的那一段的最后一个字符串改成'#' 即可。
//即 求出 s 中不重叠包含子串 ptr 的个数
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
const int N = 1e5+5;
int Next[N];
char s[N],ptr[N];
void getNext(char *ptr)
{
    mem(Next,0);
    Next[0] = -1;
    int j = 0;
    int k = -1;
    int len = strlen(ptr);
    while(j < len){
        if(k==-1 || ptr[j]==ptr[k]){
            j++;
            k++;
            Next[j] = k;
        }
        else k = Next[k];
    }
}
int KMP(char *s,char *ptr)
{
    int cnt = 0;
    getNext(ptr);
    int len_s = strlen(s);
    int len_ptr = strlen(ptr);
    int i = 0;
    int j = 0;
    while(i < len_s){
        if(j==-1 || s[i]==ptr[j]){
            i++;
            j++;
            if(j == len_ptr){
                cnt ++;
                j = 0; //这里置为 0，因为是不重叠包含
            }
        }
        else j = Next[j];
    }
    return cnt;
}
int main()
{
    scanf("%s%s",s,ptr);
    printf("%d\n",KMP(s,ptr));

    return 0;
}
/*
Input
intellect
tell
Output
1
Input
google
apple
Output
0
Input
sirisiri
sir
Output
2
*/