//CF 126B
//此题与 B 题(HDU--4763)  类似，做法几乎一样
//但是这个题遍历的时候 只能用 i=Next[i] 来遍历，如果用 (i -= (len-Next[len])) 遍历会出错
//(len - Next[len]) 即最小循环节的大小
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
void getNext(char *s)
{
    mem(Next,0);
    Next[0] = -1;
    int j=0;
    int k=-1;
    int len = strlen(s);
    while(j < len){
        if(k==-1 || s[j] == s[k]){
            j++;
            k++;
            Next[j] = k;
        }
        else k = Next[k];
    }
}
bool KMP(char *s,char *ptr,int len_s,int len_ptr){
    int i = 0;
    int j = 0;
    while(i < len_s){
        if(j == -1 || s[i] == ptr[j]){
            i++;
            j++;
            if(j == len_ptr) return true;
        }
        else j = Next[j];
    }
    return false;
}
int main()
{
    scanf("%s",s);
    getNext(s);
    int len = strlen(s);
    int ans = 0;
    for(int i=Next[len];i>=1;i = Next[i]){  
        if(KMP(s+1,s,len-2,i)) {  //在 s[1]~s[n-2] 中找到能匹配的子串，先找到的即为最长的
            ans = i;
            break;
        }
    }
    if(ans == 0) printf("Just a legend\n");
    else {
        for(int i=0;i<ans;i++){
            printf("%c",s[i]);
        }
    }
    return 0;
}
/*
Input
fixprefixsuffix
Output
fix
Input
abcdabc
Output
Just a legend
*/