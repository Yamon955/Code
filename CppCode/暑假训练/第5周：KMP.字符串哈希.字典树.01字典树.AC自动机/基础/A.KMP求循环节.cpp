//https://vjudge.net/contest/454813  题集
//KMP  字符串哈希  字典树   01字典树    ac自动机
//


//HDU 3746
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
const int N = 1e5+5;
int n;
char s[N];
int Next[N];
void getnext(char *s)
{
    int len = strlen(s);
    Next[0] = -1;
    int k = -1,j=0;
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
    scanf("%d",&n);
    while(n--){
        mem(Next,0);
        scanf("%s",s);
        getnext(s);
        int len = strlen(s);
        //for(int i=0;i<=len;i++) cout<<Next[i]<<"  ";
        //cout<<endl;
        if(Next[len] == 0){      //如果 Next[len] = 0 表示当前序列的循环节长度为 len,即该序列本身就是一个循环节
            printf("%d\n",len);  //所以还需要再添加一个长度为len的该序列来构成含有两个长度为 len 的循环节的序列
            continue; 
        }
        int num = len - Next[len];     //表示含有的循环节长度为 num
        cout<<num<<endl;
        if(len%num==0) printf("0\n");  //如果该序列正好含有整数个循环节，则不用在另外添加额外的字母来构成完整的循环节，即该序列本身含有的循环节都是完整的
        else printf("%d\n",num-len%num);
    }
}
/*
Sample Input
3
aaa
abca
abcde
Sample Output
0
2
5
*/