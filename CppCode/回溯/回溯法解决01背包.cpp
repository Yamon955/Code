#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//////////////////////////////////////////////回溯 + 左右剪枝
int c;  //背包容量
int n;  //物品数
int w[10010];//物品重量数组
int v[10010];//物品价值数组
int cw;//当前重量
int cv;//当前价值
int best=-0x3f3f3f3f;//当前最优价值
int x[10010];//值为0或1表示当前物品是否装进背包
int ans[10010];
class tmp{
    public:
        double tmp_w_avg;//物品的单位体积的价值
        int    tmp_w;//物品的重量
        int    tmp_v;//物品的价值
};
bool cmp(tmp x,tmp y)
{
    return x.tmp_w_avg > y.tmp_w_avg;//按照物品的单位体积的价值从大到小排序
}
double Bound(int x)
{
    tmp t[10010];
    int c_left = c - cw;//计算背包剩余空间大小，将这部分空间按照完全背包(贪心)处理
    double tmp_v = cv;//当前价值
    int i;
    int count=0;//计数器，统计剩余物品的个数
    for(i=x;i<n;i++){  //要从当前物品的下一个物品开始遍历，因为已经确定当前物品不取了
        t[count].tmp_w_avg = 1.0*v[i]/w[i];//计算物品的单位体积的价值
        t[count].tmp_v = v[i];
        t[count++].tmp_w = w[i];
    }
    sort(t,t+count,cmp);//按照物品的单位体积的价值从大到小排序，因为要按照贪心策略处理剩余的背包空间
    for(i=0;i<count;i++){  //贪心处理完全背包
        if(c_left>=t[i].tmp_w){ 
            c_left -= t[i].tmp_w;
            tmp_v += t[i].tmp_v;
        }
        else break;
    }
    if(i<n){ 
        tmp_v += t[i].tmp_w_avg *c_left;//将剩余不足一个物品大小的空间装满，即切割物品填满空间大小
    }
    return tmp_v;
}
void Backtrack(int i)
{
    if(i==n){
        best = cv; //可以想一下这里为什么不用加判断条件if(cv > best),结合右子树的剪枝策略
        for(int j=0;j<n;j++) ans[j] = x[j];
        return ;
    }
    if(cw+w[i]<=c){  //左子树(即x[i]==1的分支)剪枝，即如果当前重量加上当前物品的重量小于背包的总容量，才可以将此物品装入背包，
                    //否则，当前物品不能装入包中，即x[i]不能等于1，即不能走左分支(x[i]==1的分支)
        x[i]=1;
        cv+=v[i];
        cw+=w[i];
        Backtrack(i+1);
        x[i]=0;   //回溯
        cv-=v[i];
        cw-=w[i];
    }
    if(Bound(i+1)>best){  
/*右子树(即x[i]==0的分支)剪枝，即当前的物品不加入背包中，判断后面的物品最大程度的装入背包(即按照部分背包的处理方法将剩余
背包的容量完全装满,即贪心策略，依次按照将单位重量价值大小装入背包)，这样处理后装满背包后的最优解肯定大于实际上的最优解，
如果按照部分背包处理后的最优解还小于当前的最优解，就说明当前的右分支(即x[i]==0的分支)不用向下遍历了，因为它的最优解
肯定小于该背包的最优解，
如果按照部分背包处理后的最优解大于当前的最优解，就说明当前的右分支(即x[i]==0的分支)可以向下遍历了，因为它的
最优解可能会大于当前的最优解而成为新的更大的最优解(只是可能)
*/
        x[i]=0;//可有可无，因为x[i]初始就是0
        Backtrack(i+1);
    }
}
int main()
{
    cin>>n>>c;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        w[i]=a;
        v[i]=b;
    }
    Backtrack(0);
   for(int j=0;j<n;j++) cout<<ans[j]<<" ";
    cout<<endl;
    cout<<best<<endl;
    return 0;
}
/*
4 7
3 9
5 10
2 7
1 4
---->20

5 10
2 6
2 3
6 5
5 4
4 6
----->15
*/