#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,c1,c2;
int w[100];
int bestw; //最优载重
int cw;   
queue<int> q;
void EnQueue(int wt,int& bestw,int i)  //将活结点加入到活结点队列q中
{
    if(i==n){           //叶子节点
        if(wt>bestw) {
            bestw = wt;  //只有在找到第一个叶子节点的时候才会开始更新
        }
    }
    else q.push(wt);   //非叶节点
}
int main()
{
    cin>>n>>c1>>c2;
    for(int i=1;i<=n;i++) cin>>w[i];
    q.push(-1); // -1 作为同层结束的标记
    int i=1;
    while(true){
        if(cw+w[i]<=c1){
            EnQueue(cw+w[i],bestw,i); //左支，即装此物品
        }
        EnQueue(cw,bestw,i); //右支，即不装此物品
        cw = q.front();  //取出当前头节点
        q.pop();  //当前处理完的节点出队，也可能是 -1 出队
        if(cw==-1){  //当前层已经处理完毕，即该层所有节点都已经扩展完毕
            if(q.empty()){ //取出 -1 后如果队列为空，说明已经全部处理完毕，得到了最优值bestw
                break;  
            }
            q.push(-1); //增加该层的结束标志
            cw = q.front();//取出新一层的第一个节点的载重量，去扩展
            q.pop();
            i++; //处理下一个物品
        }
    }
    if(bestw==0) cout<<"no solution"<<endl;
    else {
        cout<<bestw<<endl;
    }
    return 0;
}
/*
Simple input：
10 500 121
21 54 21 45 20 65 320 1 20 54
Simple output：
500
*/