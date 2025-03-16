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
const int N = 1e5+5;
int n;
double z,r;
double a[N];
double sum = 0;
double vis[N];
vector<int>v[N];
void dfs(int x,double w)
{
    if(vis[x]!=0){
        sum += w*vis[x];
    }
    for(int i=0;i<v[x].size();i++){
        dfs(v[x][i],w*(100-r)/100);
    }
}
int main()
{
    cin>>n>>z>>r;
    a[0] = z;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k == 0){
            double x;
            cin>>x;
            vis[i] = x;
        }
        else{
            int x;
            while(k--){
                cin>>x;
                v[i].push_back(x);
            }
        }
    }
    dfs(0,z);
    //for(int i=0;i<n;i++) cout<<a[i]<<endl;
    cout<<(int)sum<<endl;
}
/*
输入样例：
10 18.0 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
结尾无空行
输出样例：
404
*/