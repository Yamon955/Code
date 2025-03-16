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
#include<set>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int N = 500+5;
int v,e,k,n;
int f[N][N];
int a[N];
int main()
{
    cin>>v>>e>>k;
    while(e--){
        int u,v;
        cin>>u>>v;
        f[u][v] = f[v][u] = 1;
    }
    cin>>n;
    while(n--){
        mem(a,0);
        set<int>st;
        int flag = 1;
        for(int i=1;i<=v;i++){
            int x;
            cin>>x;
            a[i] = x;
            st.insert(x);
            if(!flag) continue;
            for(int j=1;j<=v;j++){
                if(f[i][j] && a[i] == a[j]){
                    flag = 0;
                    break;
                }
            }
        }
        //这题必须出现k种颜色，不多不少(但是题目没有说)
        if(flag && st.size()==k) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }


}
/*
输入样例：
6 8 3
2 1
1 3
4 6
2 5
2 4
5 4
5 6
3 6
4
1 2 3 3 1 2
4 5 6 6 4 5
1 2 3 4 5 6
2 3 4 2 3 4
结尾无空行
输出样例：
Yes
Yes
No
No
*/