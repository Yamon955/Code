//HDU1896
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int T,n;
ll ans;
struct node{
    ll p;
    int d;
    bool operator <(const node &a)const{
        if(p==a.p) return d > a.d;
        else return p > a.p;
    }
};
priority_queue<node>q;
int main()
{
    scanf("%d",&T);
    while(T--){
        while(!q.empty()) q.pop();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int p,d;
            scanf("%d%d",&p,&d);
            node tmp;
            tmp.p = p;
            tmp.d = d;
            q.push(tmp);
        }
        int cnt = 0;
        while(!q.empty()){
            node u = q.top();
            q.pop();
            cnt++;
            if(cnt%2!=0) {
                node tmp;
                tmp.p = u.p+u.d;
                tmp.d = u.d;
                q.push(tmp);
            }
            if(q.empty()) ans = u.p;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
示例输入
2
2
1 5
2 4
2
1 5
6 6
样本输出
11
12
*/
