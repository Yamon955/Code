#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<vector>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+5;
int T,m,n;
vector<int>v[N];
int main()
{
    cin>>T;
    int Case = 0;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++){
            int num;
            cin>>num;
            for(int j=1;j<=num;j++){
                int x;
                cin>>x;
                v[i].push_back(x);
            }
        }
        printf("Case #%d: \n",++Case);
        while(m--){
            int now,num;
            cin>>now>>num;
            int flag = 0;
            for(int i=1;i<=num;i++){
                int ct;
                cin>>ct;
                int len = v[now].size();
                if(len >= ct){
                    now = v[now][ct-1];
                }
                else{
                    flag = 1;
                }
            }
            if(flag) cout<<"Packet Loss"<<endl;
            else cout<<now<<endl;
        }
    }
}
/*
Sample Input
1
4 3
2 2 3
0
2 4 3
0
1 2 2 1
1 2 2 2
1 2 1 1
Sample Output
Case #1: 
4
3
Packet Loss
*/