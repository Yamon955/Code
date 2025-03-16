#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int n,c1,c2;
int w[100];
int bestw; //最优载重
int cw;   
int bestv[100];
int sum;  //所有物品之和
int len; //最优解的长度
struct Qnode{
    Qnode* parent;
    bool lchild;
    int w;
};
Qnode *newQnode = (Qnode*)malloc(sizeof(Qnode));//不要忘记节点开辟空间
queue<Qnode *>q;
int main()
{
    cin>>n>>c1>>c2;
    for(int i=1;i<=n;i++) {
        cin>>w[i];
        sum+=w[i];
    }
    sum = sum-w[1]; //所有物品重量之和减去第一件物品的重量
    Qnode *st = (Qnode*)malloc(sizeof(Qnode)); //起始节点
    st->w = -1;
    st->parent = NULL;//初始节点，指向空
    newQnode = st;
    q.push(st);
    int i = 1;
    while(true){
        if(cw+w[i]<=c1 && i<n){
            Qnode *tmp = (Qnode*)malloc(sizeof(Qnode));
            tmp->parent = newQnode;
            tmp->lchild = true; //左支
            tmp->w = cw+w[i];
            q.push(tmp);  //左支进队
            if(cw+w[i] > bestw) {  //约束函数
                bestw = cw+w[i];  //实时更新最优值
                int j = 0;
                while(tmp->parent!=NULL){   //记录下当前最优值对应的最优解
                    if(tmp->lchild)  bestv[++j] = 1;  
                    else bestv[++j] = 0;
                    tmp = tmp->parent;
                }   
                len = j; //记下最优解的长度，即到第几个物品是最优解，
            //而该物品的后面如果还有物品的话则全部不取，这也是为什么输出最优解之后还要打印后续可能存在的 0 
            }
        }
        if(cw+sum > bestw && i<n){   //限界函数
            Qnode *tmp = (Qnode*)malloc(sizeof(Qnode));
            tmp->w = cw;
            tmp->lchild = false;
            tmp->parent = newQnode;
            q.push(tmp); //右支进队
        }
        cw = q.front()->w;
        newQnode = q.front();//保存当前的首节点
        q.pop();  //首节点出队 --> 表示接下来扩展该节点   也可能是 -1 出队
        if(cw==-1){
            if(q.empty()) break;
            Qnode *rear = (Qnode*)malloc(sizeof(Qnode));  //每层结束标记节点
            rear->w = -1;
            rear->parent = NULL;
            q.push(rear);  //结束标志节点进队
            cw = q.front()->w;
            newQnode = q.front(); //保存当前的首节点
            q.pop(); //首节点出队 --> 表示接下来扩展该节点
            i++;
            sum = sum - w[i]; //剩余物品的重量之和
        }
    }
    if(bestw==0) cout<<"no solution"<<endl;
    else {
        cout<<bestw<<endl;  //输出最优值
        for(int i=len;i>0;i--) cout<<bestv[i]<<" ";  //输出最优解
        for(int i=len+1;i<=n;i++) cout<<"0 "; //补充后面可能存在的 0 
    }
    return 0;
}
/*
Simple input：
10 500 121
21 54 21 45 20 65 320 1 20 54
Simple output：
500
1 1 0 0 1 1 1 0 1 0
*/