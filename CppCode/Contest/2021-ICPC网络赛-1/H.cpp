#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
#include<vector>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int ans_idx[N];
struct cmp{
    bool operator() (const ll a,const ll b)const{
        return a<b;
    }
};
set<ll,cmp>ans; //声明一个集合，并且其中元素从小到大排列
struct node{
    ll x,y,z;
    int pos;
};
node Ns[N];
int m,n,q;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        double idx,X,Y,Z;
        cin>>idx>>X>>Y>>Z;  //根本没有用，sb 题
    }

    for(int i=1;i<=m;i++){
        ll idx,op;
        cin>>idx>>op;
        if(op == 203){
            cin>>Ns[i].x>>Ns[i].y>>Ns[i].z;
            Ns[i].pos = 203;
        }
        else{
            cin>>Ns[i].x>>Ns[i].y;
            Ns[i].pos = 102;
        }
    }
    cin>>q;
    int cnt = 0;
    while(q--){
        ans.clear();
        cnt = 0;
        ll w;
        cin>>w;
        for(int i=1;i<=m;i++){
            if(Ns[i].x==w || Ns[i].y==w || (Ns[i].pos==203 && Ns[i].z==w)) ans_idx[cnt++] = i;
            if(Ns[i].pos == 203){
                if(Ns[i].x == w){
                    if(Ns[i].y!=w) ans.insert(Ns[i].y);
                    if(Ns[i].z!=w) ans.insert(Ns[i].z);
                }
                else if(Ns[i].y == w){
                    if(Ns[i].x!=w) ans.insert(Ns[i].x);
                    if(Ns[i].z!=w) ans.insert(Ns[i].z);
                }
                else if(Ns[i].z == w){
                    if(Ns[i].x!=w) ans.insert(Ns[i].x);
                    if(Ns[i].y!=w) ans.insert(Ns[i].y);
                }
            }
            else{
                if(Ns[i].x == w){
                    if(Ns[i].y!=w) ans.insert(Ns[i].y);
                }
                if(Ns[i].y == w){
                    if(Ns[i].x!=w) ans.insert(Ns[i].x);
                }
            }
        }
        cout<<w<<endl;
        printf("[");
        int flag = 0;
        set<ll>::iterator it;
        for(it = ans.begin();it!=ans.end();it++){
            if(flag == 0){
                printf("%lld",*it);
                flag = 1;
            }
            else{
                printf(",%lld",*it);
            }
            
        }
        printf("]\n");
        printf("[");
        flag = 0;
        for(int i=0;i<cnt;i++){
            if(flag == 0){
                printf("%lld",ans_idx[i]);
                flag = 1;
            }
            else{
                printf(",%lld",ans_idx[i]);
            }
            
        }
        printf("]\n");
        //if(q != 0) cout<<endl; //题目要求最后一行没有空行，但是有也可以过
    }
}
/*
Sample Input
8 6
1 0.0 1.1 0.0
2 1.5e1 2.1e1 0.0
3 2.3 0.1 0.0
4 3.0 1.8 0.0
5 3.4 0.2 0.0
6 4.2 2.3 0.0
7 5.5 -0.1 0.0
8 6.1 1.9 0.0
1 203 1 2 3
2 203 2 3 4
3 203 3 4 5
4 203 4 5 6
5 203 5 6 7
6 102 5 8
2
5
9
Sample Output
5
[3,4,6,7,8]
[3,4,5,6]
9
[]
[]
*/