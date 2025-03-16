//在前一个问题的基础上实时更新 bestw ,并且加了限界函数来剪去右支
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
int sum; //所有物品重量之和
queue<int> q;
int main()
{
    cin>>n>>c1>>c2;
    for(int i=1;i<=n;i++) {
        cin>>w[i];
        sum+=w[i];
    }
    sum = sum-w[1];  //这里要提前减去第一件物品的重量
    q.push(-1); // -1 作为同层结束的标记
    int i=1;
    while(true){
        if(cw+w[i]<=c1 && i < n){     //约束函数剪左支
            if(cw+w[i]>bestw) bestw = cw+w[i]; //实时更新 bestw
            q.push(cw+w[i]); //处理左支
        }
        if(cw+sum > bestw && i < n){  //限界函数剪右支
            q.push(cw);      //处理右支
        }
        cw = q.front();
        q.pop();
        if(cw==-1){
            if(q.empty()) break;
            q.push(-1);
            cw = q.front();
            q.pop();
            i++;         //进入下一层
            sum -= w[i]; //剩余货品的重量和
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