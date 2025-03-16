//CF1490D
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 105;
int T,n,a[N];
int res[N];
//递归：每遇到一个最大值，就分两段，并深度加1
void Sort(int l,int r,int h)
{
    int Max = -1;
    int idx = -1;
    for(int i=l;i<=r;i++){
       if(Max < a[i]){
           Max = a[i];
           idx = i; 
       }
    }
    res[idx] = h;

    if(l<=idx-1) Sort(l,idx-1,h+1);
    if(r>=idx+1) Sort(idx+1,r,h+1);
}

int main()
{
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        memset(res,-1,sizeof res);
        Sort(1,n,0);
        for(int i=1;i<=n;i++) cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
/*
Input
3
5
3 5 2 1 4
1
1
4
4 3 1 2
Output
1 0 2 3 1 
0 
0 1 3 2 
*/