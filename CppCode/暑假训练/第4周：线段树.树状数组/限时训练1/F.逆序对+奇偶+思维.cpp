//CodeForces - 987E
//一个序列的状态可以归为：由原序列操作奇数次得到（简称奇序列）；和操作偶数次（偶序列）得到。
// 显然奇序列中，逆序对的个数为奇数；偶序列中，逆序对的个数为偶。
// 当n为奇数时，3*n为奇，7*n+1为偶；n为偶数时正好相反。
// 用树状数组或归并排序求逆序对即可。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+5;
int n;
int tree[N],b[N];
struct node{
    int x,idx;
    bool operator < (const node &a)const{
        if(x == a.x) return idx < a.idx;
        else return x < a.x;
    }
}a[N];
int lowbit(int x)
{
    return x & (-x);
}
void update(int pos,int x)
{
    for(int i=pos;i<=n;i+=lowbit(i)){
        tree[i] += x;
    }
}
ll Query(int pos)
{
    ll ans = 0;
    for(int i=pos;i;i-=lowbit(i)){
        ans += tree[i];
    }
    return ans;
}
int main()
{
    while(cin>>n && n){
        mem(tree,0);
        mem(a,0);
        mem(b,0);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].x);
            a[i].idx = i;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            b[a[i].idx] = i;
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            update(b[i],1);
            ans += Query(n) - Query(b[i]);
        }
        if(n%2)
            if(ans % 2==1)
        	    cout<<"Petr"<<endl;
    	    else cout<<"Um_nik"<<endl;
        else{
            if(ans % 2==0)
        	    cout<<"Petr"<<endl;
    	    else cout<<"Um_nik"<<endl;
        }
    }
}