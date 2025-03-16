//HDU 2087
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
const int N = 1e3+5;
char s[N],ptr[N];
int nt[N];
int cnt;
void getnext(char *s)  //求 next[] 数组
{
    int len = strlen(s);
    nt[0] = -1;
    int k = -1;
    int j = 0;
    while(j < len){
        if(k == -1 || s[j] == s[k]){
            j++;
            k++;
            nt[j] = k;
        }
        else k = nt[k];
    }
}
void KMP(char *s,char *ptr)  //KMP 算法
{
    int len_s = strlen(s);
    int len_ptr = strlen(ptr);
    int i = 0;
    int j = 0;
    while(i < len_s){
        if(j == -1 || s[i] == ptr[j]){
            i++;
            j++;
            if(j == len_ptr){
                cnt ++;
                j = 0;
            }
        }
        else{
            j = nt[j];
        }
    }
}
int main()
{
    while(scanf("%s",s)!=EOF){
        if(s[0] == '#') break;
        scanf("%s",ptr);
        getnext(ptr);
        cnt = 0;
        KMP(s,ptr);
        printf("%d\n",cnt);
    }
    return 0;
}
/*
Sample Input
abcde a3
aaaaaa  aa
#
Sample Output
0
3
*/