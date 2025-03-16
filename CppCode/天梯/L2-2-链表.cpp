#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stdlib.h>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath> 
#include<map>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+5;
int st,n;
struct node{
    int data;
    int next;
};
node Ns[N];
map<int,int>mp;
int cnt = 0;
int a[N],b[N];
int aa,bb;
int vis[N];
int main()
{
    cin>>st>>n;
    //mp[st] = ++cnt;
    for(int i=1;i<=n;i++){
        int idx;
        cin>>idx;
        cin>>Ns[idx].data>>Ns[idx].next;
    }
    while(st != -1){
        if(vis[abs(Ns[st].data)] == 0){
            vis[abs(Ns[st].data)] = 1;
            a[aa++] = st;
            st = Ns[st].next;
        }
        else{
            b[bb++] = st;
            st = Ns[st].next;
        }
    }
    for(int i=0;i<aa;i++){
        if(i < aa-1)
            printf("%05d %d %05d\n",a[i],Ns[a[i]].data,a[i+1]);
        else{
            printf("%05d %d -1\n",a[i],Ns[a[i]].data);
        }
    }
    for(int i=0;i<bb;i++){
        if(i < bb-1)
            printf("%05d %d %05d\n",b[i],Ns[b[i]].data,b[i+1]);
        else{
            printf("%05d %d -1\n",b[i],Ns[b[i]].data);
        }
    }


}
/*
输入样例：
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
结尾无空行
输出样例：
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/