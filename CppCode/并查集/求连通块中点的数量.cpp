#include<iostream>
using namespace std;
int p[10000],Size[10000],n,m;
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
        Size[i]=1;
    }
    while(m--){
        char op[3];
        int a,b;
        cin>>op;
        if(op[0]=='C'){
            cin>>a>>b;
            if(find(a)!=find(b)){ //ab可能相等
                Size[find(a)]+=Size[find(b)];
                p[find(b)]=find(a);
            }
        }
        else if(op[1]=='1'){
            cin>>a>>b;
            if(find(a)==find(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else{
            cin>>a;
            cout<<Size[find(a)]<<endl;
        }
    }
    return 0;
}
//AC wing 837

/*
题目描述：
给定一个包含n个点（编号为1~n）的无向图，初始时图中没有边。
现在要进行m个操作，操作共有三种：

“C a b”，在点a和点b之间连一条边，a和b可能相等；
“Q1 a b”，询问点a和点b是否在同一个连通块中，a和b可能相等；
“Q2 a”，询问点a所在连通块中点的数量；
输入格式
第一行输入整数n和m。
接下来m行，每行包含一个操作指令，指令为“C a b”，“Q1 a b”或“Q2 a”中的一种。
输出格式
对于每个询问指令”Q1 a b”，如果a和b在同一个连通块中，则输出“Yes”，否则输出“No”。
对于每个询问指令“Q2 a”，输出一个整数表示点a所在连通块中点的数量
每个结果占一行。
数据范围
1≤n,m≤10^5
输入样例：
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5
输出样例：
Yes
2
3
*/