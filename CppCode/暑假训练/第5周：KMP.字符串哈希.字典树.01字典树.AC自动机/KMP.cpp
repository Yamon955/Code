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
                j = 0; //求不重叠的子串的个数     HDU 2087
                //j = Next[j]   求重叠子串的个数  POJ 3461
            }
        }
        else{
            j = Next[j];
        }
    }
}
/*
KMP Next数组作用
1.求最小循环节  --->基础 A 题(HDU 3746)   和  提高 C 题(HDU 1358)
   假设字符串 s   len = strlen(s)
   s 中最小循环节大小为   num = len - Next[len]
        如 s="abcdvfab" 那么最小循环节长度 num = 6 即为 "abcdvf"
        需要最少填上 num - len%num = 4 个字符(即填上 "cdvf")就使字符串 s 就变成了整数个循环节构成的
2.遍历递减循环节  --->提高中的 B题(HDU 4763) 和 F题(CF--126B)  
    i = Next[i] 相当于 i -= num (num = len%Next[len]  为最小循环节的长度)
3.求每个前缀出现的次数(dp)  --->提高中的 K题(CF--432D)
    //dp[i] 代表 s[0]~s[i-1] 在字符串中出现的次数 可以看 k 题

        for(int i=0;i<=len;i++) dp[i] = 1 //初始化每种前缀都出现 1 次
        for(int i=len;i>=1;i--)
            dp[Next[i]] += dp[i];
        
        如 s = "absabdab"
          dp[1] = 3 即 "a"出现了 3 次
          dp[2] = 3 即 "ab"出现了 3 次
          dp[8] = 1 即 "absabdab"出现了 1 次

*/