//https://vjudge.net/contest/454814

//POJ 3461
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
int n;
int Next[N];
char s[N],ptr[N];
void getNext(char *ptr)
{
    int len = strlen(ptr);
    Next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < len){
        if(k==-1 || ptr[j]==ptr[k]){
            j ++;
            k ++;
            Next[j] = k;
        }
        else k = Next[k];
    }
}
int KMP(char *s,char *ptr)
{
    int cnt = 0;
    mem(Next,0);
    getNext(ptr);
    int len_s = strlen(s);
    int len_ptr = strlen(ptr);
    int i = 0,j = 0;
    while(i < len_s){
        if(j==-1 || s[i]==ptr[j]){
            i++;
            j++;
            if(j == len_ptr){
                j = Next[j];
                cnt++;
            }
        }
        else j = Next[j];
    }
    return cnt;
}
int main()
{
    scanf("%d",&n);
    while(n--){
        scanf("%s%s",ptr,s);
        printf("%d\n",KMP(s,ptr));
    }
    return 0;
}
/*
Sample Input
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
Sample Output
1
3
0
*/
