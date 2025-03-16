#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<malloc.h>
#include<queue>
#include<cmath>
using namespace std;
int n,m;
int map[100][100];
int best = 0; //最优值
int bestv[100]; //保存最优解
int len = 0; //最优解的长度，也就是最优值 best
typedef struct Node{
    int no; //当前处理的点的编号
    int cnt; //团中点的个数
    Node *parent; //指向前一个节点，即由那个节点扩展而来
    bool lchild;  //判断走的左支还是右支，即当前的点是否在团中
}Node;
queue<Node *>q;
Node* newNode = (Node *)malloc(sizeof(Node));
bool check(Node *n,int x)  //判断当前点 x ,与newNode.no点是否在一个团中
{
    Node* tmp = (Node *)malloc(sizeof(Node));
    tmp = n;
    while(tmp->parent!=NULL){
        if(map[tmp->no][x]==0) return false; //如果点 x 与该团中的任意一个节点不连通，则点 x 不能扩展到该团中
        tmp = tmp->parent;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        map[u][v] = map[v][u] = 1;
    }
    Node *st = (Node *)malloc(sizeof(Node));
    st->no = -1; //起始节点
    st->cnt = 0;
    st->parent=NULL; //起始节点的父节点为空
    q.push(st);
    newNode = st;
    int level = 1; //代表层数，也就是要处理的点的编号
    while(!q.empty()){
        if(level==1||(map[newNode->no][level]==1 && check(newNode,level))){ //约束函数
            Node *tmp = (Node *)malloc(sizeof(Node));
            tmp->no = level;
            tmp->parent = newNode;
            tmp->lchild = true;  //左支
            tmp->cnt = newNode->cnt+1; //团中的节点数 +1
            q.push(tmp);
            if(tmp->cnt > best){
                best = tmp->cnt;  //实时更新最优值 best
                len = 0;
                while(tmp->parent!=NULL){
                    if(tmp->lchild) bestv[++len] = tmp->no;  //保存最优解
                    else bestv[++len] = 0;
                    tmp=tmp->parent;
                }
            }
        }
        if(level==1||(newNode->cnt+n-level > best)){ //限界函数
            Node *tmp = (Node *)malloc(sizeof(Node));
            tmp->no = level;
            tmp->parent = newNode;
            tmp->lchild = false; //右支
            tmp->cnt = newNode->cnt;
            q.push(tmp);
        }
        newNode = q.front();
        q.pop();  //每个扩展完的节点出队，也可能是 -1 结束标志节点出队
        if(newNode->no==-1){  //当前层已经处理完了
            Node *tmp = (Node *)malloc(sizeof(Node));
            tmp->no = -1;
            tmp->parent = NULL;
            q.push(tmp);  //增加每层的结束标记
            newNode = q.front();
            q.pop();
            level++;  //处理下一层，即下一个编号的点
        }
    }
    cout<<best<<endl;
    for(int i=len;i>0;i--) cout<<bestv[i]<<" ";
    return 0;

}
/*
Simple input：
3 3
1 2 
1 3 
2 3 
Simple output：
3
1 2 3
*/