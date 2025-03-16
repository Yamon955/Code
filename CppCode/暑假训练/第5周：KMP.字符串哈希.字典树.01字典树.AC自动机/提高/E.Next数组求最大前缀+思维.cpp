//CF 1137B
// 道题考察的 主要是阅读理解 主要是 next数组 求最长公共前后缀。

// 为什么要找公共前后缀 ：
// 记 t  串最长公共前后缀为 p ，记前缀 p 的最后一个字母索引是 idx，
// 再记 t 的索引范围为 [ idx + 1 ，len(t) − 1 ]的子串是 r
// 构造串 a = ( t + r + r + r + . . . )显然此种构造方式是最省字母的让 t  多次出现的构造方式。·
// 因此我们将 s 重排的目标就是把它弄成 a 这种结构，直到 “字符原料” 不足以再拼凑更多的 r 串。
// 然后关键来了：为什么这样对 s重排就一定能使 t 出现次数最多呢？
// 显然，由于重排过程 “字符数量守恒”，如果最省字母的构造方式都不够再让 t 出现更多次，那么其他的构造方式就更不可能了

//用贪心的思想,尽量用 t 首尾相连的去凑出S。比如S="00111",T="101",那么我们可以把两个101拼在一起，相同的前后缀合并,变成10101
 //即 先拼凑一个 t 的公共前后缀部分，接下来尽可能拼凑除去前缀的剩余部分

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
const int N = 5e5+5;
char s[N],t[N];
int a[2];
int Next[N];
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
int main()
{
    scanf("%s%s",s,t);
    int len_s = strlen(s);
    int len_t = strlen(t);
    getNext(t);
    for(int i=0;i<len_s;i++){
        a[s[i]-'0']++;  //a[0] : 串 s 中 0 的个数    a[1] : 串 s 中 1 的个数
    }
    int x = 0,y = 0;  //拼凑一个最大公共前后缀所需 0 的个数为 x 个  1 的个数为 y 个
    for(int i=0;i<Next[len_t];i++){
        if(t[i]=='0') x++;
        else y++;
    }
    if(a[0]>=x && a[1]>=y){ //如果能够拼成一个 t 的最大公共前后缀，就拼一个
        for(int i=0;i<Next[len_t];i++)
            printf("%c",t[i]);
        a[0] -= x;
        a[1] -= y;
    }
    int xx = 0,yy = 0;  //拼凑除去最大公共前后缀的剩余部分所需 0 的个数为 xx 个  1 的个数为 yy 个
    for(int i=Next[len_t];i<len_t;i++){
        if(t[i]=='0')  xx++;
        else yy++;
    }
    while(a[0] >= xx && a[1] >= yy){
        for(int i=Next[len_t];i<len_t;i++)
            printf("%c",t[i]);
        a[0] -= xx;
        a[1] -= yy;
    }
    while(a[0] > 0){  //最后剩余的 0 
        cout<<"0";
        a[0]--;
    }
    while(a[1] > 0){  //最后剩余的 1 
        cout<<"1";
        a[1]--;
    }
    return 0;
}
/*
Input
101101
110
Output
110110
Input
10010110
100011
Output
01100011
Input
10
11100
Output
01

（输出答案不唯一）
*/