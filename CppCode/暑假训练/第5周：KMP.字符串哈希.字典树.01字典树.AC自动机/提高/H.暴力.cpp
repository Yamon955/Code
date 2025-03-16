//CF--716B
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
const int N = 5e4+5;
char s[N],ptr[N];
int a[30];
int num_ch,num;
int flag1,flag2;
int main()
{
    scanf("%s",s);
    int len = strlen(s);
    if(len < 26) {
        cout<<"-1"<<endl;
        return 0;  //这里不要忘记直接 return 0
    }
    flag2 = 0;
    for(int i=0;i+25<len;i++){  //从左到右枚举每一段的26个字母
        mem(a,0);
        flag1 = 0;
        for(int j=i;j<i+26;j++){
            if(s[j] == '?') continue;
            else a[s[j]-'A']++;
            if(a[s[j]-'A']>1){
                flag1 = 1;
                break;
            }
        }
        if(!flag1){
            flag2 = 1;
            int j;
            for(j=i;j<i+26;j++){
                if(s[j] == '?'){
                    for(int k=0;k<26;k++)
                        if(a[k]==0){
                            s[j] = 'A'+k;
                            a[k]++;
                            break;
                        }
                }
            }
            if(flag2){
                break;
            }
        }
            
    }
    if(flag2){
        for(int i=0;i<len;i++){
            if(s[i]=='?') s[i] = 'A';
        }
        cout<<s;
    }
    else cout<<"-1"<<endl;
    return 0;
}
/*
Input
ABC??FGHIJK???OPQR?TUVWXY?
Output
ABCDEFGHIJKLMNOPQRZTUVWXYS
Input
WELCOMETOCODEFORCESROUNDTHREEHUNDREDANDSEVENTYTWO
Output
-1
Input
??????????????????????????
Output
MNBVCXZLKJHGFDSAQPWOEIRUYT
Input
AABCDEFGHIJKLMNOPQRSTUVW??M
Output
-1
*/
