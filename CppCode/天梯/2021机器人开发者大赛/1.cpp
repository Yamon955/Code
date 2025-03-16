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
#include<utility>
#include<set>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 55;
int n,k;
int a[N];
set<double>s;
void dfs(int x,int step,int sum)
{
    if(step == 4){
        double ss = 1.0*sum/4;
        s.insert(ss);
        return;
    }
    for(int i=x;i<=n;i++){
        dfs(i+1,step+1,sum+a[i]);
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,0);
    for(int i=1;i<=k;i++){
        int m,x;
        int flag = 1;
        cin>>m;
        while(m--){
            cin>>x;
            if(find(s.begin(),s.end(),x) == s.end()){
                flag = 0;
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
/*
输入样例:
5 3
4 8 12 20 40
3 11 16 19
3 12 16 19
10 11 11 11 11 11 11 11 11 11 11
结尾无空行
输出样例:
Yes
No
Yes
*/