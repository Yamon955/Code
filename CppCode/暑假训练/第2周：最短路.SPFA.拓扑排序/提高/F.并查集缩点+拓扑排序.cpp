//HDU1811 并查集缩点+拓扑排序
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e4+5;
int n,m,x[N],y[N];
char op[N];
struct Edge{
    int to;
    int next;
};
Edge edge[N*5];
int h[N],tol,d[N],p[N],cnt;
int flag;
int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
void add(int u,int v)
{
    edge[tol].to = v;
    edge[tol].next = h[u];
    h[u] = tol++;
}
void topsort()
{
    queue<int>q;
    int flag = 0;
    for(int i=0;i<n;i++){
        if(d[i]==0 && p[i]==i) //除了入度为0外还要保证必须是根节点，根结点才参与建图
            q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        if(q.size()>1)  flag = 1;//缺少信息
        q.pop();
        cnt++;
        for(int i=h[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            d[v]--;
            if(d[v]==0) q.push(v);
        }
    }
    if(cnt<n) cout<<"CONFLICT"<<endl;
    else if(flag==1) cout<<"UNCERTAIN"<<endl;
    else cout<<"OK"<<endl;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(h,-1,sizeof h);
        memset(d,0,sizeof d);
        for(int i=0;i<n;i++) p[i]=i;
        cnt = 0;
        //先处理'='带来的点的减少，建立并查集缩点
        for(int i=1;i<=m;i++){
            cin>>x[i]>>op[i]>>y[i];
            if(op[i]=='='){
                if(find(x[i])!=find(y[i])){
                    p[find(x[i])] = find(y[i]);
                    cnt ++;  //缩点了别忘了cnt++,因为相当于总点数减少了一个
                }
                    
            }
        }
        //根据缩完点的点边关系，建图
        //也就是说最后只有根结点才参与建图
        for(int i=1;i<=m;i++){
            int x_f=find(x[i]);//根结点才参与建图
            int y_f=find(y[i]);
            if(op[i]=='>'){
                add(x_f,y_f);//根结点才参与建图
                d[y_f]++;  
            }
            else if(op[i]=='<'){
                add(y_f,x_f);//根结点才参与建图
                d[x_f]++;
            }
        }
        //并查集处理完建图之后就是常规的拓扑排序
        topsort();
    }
    return 0;
}
/*
Sample Input
3 3
0 > 1
1 < 2
0 > 2
4 4
1 = 2
1 > 3
2 > 0
0 > 1
3 3
1 > 0
1 > 2
2 < 1
Sample Output
OK
CONFLICT
UNCERTAIN
*/