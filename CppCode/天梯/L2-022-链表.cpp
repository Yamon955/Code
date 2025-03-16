#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>
#include<cmath> 
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int N = 1e6+5;
struct node{
    int data;
    int next;
};
node Ns[N];
int a[N];
int st,n;
int main()
{
    cin>>st>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cin>>Ns[x].data>>Ns[x].next;
    }
    int num = 0;
    for(;st!=-1;st=Ns[st].next){
        a[num++] = st;
    }
    for(int i=num-1,j=0;i>=j;i--,j++){
        if(i==j){
            printf("%05d %d -1\n",a[i],Ns[a[i]].data);
        }
        else if(i==j+1){
            printf("%05d %d %05d\n",a[i],Ns[a[i]].data,a[j]);
            printf("%05d %d -1\n",a[j],Ns[a[j]].data);
        }
        else{
            printf("%05d %d %05d\n",a[i],Ns[a[i]].data,a[j]);
            printf("%05d %d %05d\n",a[j],Ns[a[j]].data,a[i-1]);
        }
    }
}
/*
输入样例：
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
结尾无空行
输出样例：
68237 6 00100
00100 1 99999
99999 5 12309
12309 2 00000
00000 4 33218
33218 3 -1
*/