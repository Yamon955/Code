//https://blog.csdn.net/qq_37493070/article/details/77164903
//HDU 4763
//此题就是求出字符串的最长的相同的前缀和后缀(即 Next[len] 的值),假设为 字符串s， 
//然后再判断字符串除去前缀 s 和后缀 s 剩余中间部分是否包含字符串 s
//如字符串 ababababab -->Next[10] = 8  故其公共前后缀字符串 s = abababab -->发现前后有重叠部分，中间部分为 0
//所以我们每次从前后缀中减去一个循环节 ab 来扩充中间部分
//直到中间部分包含 当前的公共前后缀字符串(对于此例子来说 最后的公共前后缀应该为 ab )
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
void getnext(char *s)  //求 next[] 数组
{
    int len = strlen(s);
    Next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < len){
        if(k == -1 || s[j] == s[k]){
            j++;
            k++;
            Next[j] = k;
        }
        else k = Next[k];
    }
}
bool KMP(char *s,char *ptr,int len_s,int len_ptr)
{
    mem(Next,0);
    getnext(ptr);
    int i=0,j=0;
    while(i < len_s){
        if(j==-1 || s[i]==ptr[j]){
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
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        mem(Next,0);
        getnext(s);
        int len = strlen(s);
        //for(int i=0;i<=len;i++) cout<<Next[i]<<" ";
        //cout<<endl;
        int ans = 0;
        int num = len - Next[len];  //最小循环节的大小
        //cout<<num<<endl;
        for(int i=Next[len];i>=1;i -= num){  //遍历中间部分，如果中间部分比较小，则前缀和后缀各减去一个循环节
                                            //这里每次减去一个循环节 i -= num 就相当于下面注释部分的 i = Next[i]
                                            //最好还是用下面的遍历方法 i = Next[len]
            if(KMP(s+i,s,len-i*2,i)){
                ans = i;
                break;
            }
        }
        // for(int i=Next[len];i>=1;i = Next[i]){  //遍历中间部分，如果中间部分比较小，则前缀和后缀各减去一个循环节
        //     if(KMP(s+i,s,len-i*2,i)){
        //         ans = i;
        //         break;
        //     }
        // }
        printf("%d\n",ans);
    }
    return 0;
}
/*
Sample Input
5
xy
abc
aaa
aaaaba
aaxoaaaaa
Sample Output
0
0
1
1
2
*/