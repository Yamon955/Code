//CF 182D
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
char s[N],t[N];
int Next[N];

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
    scanf("%s%s",s,t);

    getNext(s);
    int len_s = strlen(s);           //字符串 s 的长度
    int num_s = len_s - Next[len_s]; //字符串 s 的最小循环节大小
    if(len_s%num_s) num_s = len_s;   //如果 s 的长度不能整除最小循环节的话，那么 s 的最小约数就只能是他自身

    getNext(t);
    int len_t = strlen(t);             //字符串 t 的长度
    int num_t = len_t - Next[len_t];   //字符串 t 的最小循环节大小
    if(len_t%num_t) num_t = len_t;    //如果 t 的长度不能整除最小循环节的话，那么 t 的最小约数就只能是他自身

    if(num_s!=num_t)  //如果两个约数长度不一样的话 (公约数长度一定相等)
        cout<<"0";
    else{
        for(int i=0;i<num_s;i++){
            if(s[i]!=t[i]){  //如果两个相等长度的循环节不相同
                cout<<"0";
                return 0;
            }
        }
        int ans = 0;
        for(int i=num_s;i<=len_s&&i<=len_t;i+=num_s){  //遍历 k 倍
            if(len_s%i == 0 && len_t%i ==0) ans ++;
        }
        cout<<ans<<endl;
    }
    
    return 0;

}
/*
Input
abcdabcd
abcdabcdabcdabcd
Output
2
Input
aaa
aa
Output
1
*/