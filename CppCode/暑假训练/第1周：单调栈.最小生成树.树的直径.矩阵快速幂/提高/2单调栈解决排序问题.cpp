//CodeForces 631C
// 把没用的操作去掉 是的操作范围从大到小单调排序

// 然后设两个变量指向头尾 根据操作把值附上即可
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int n,m;
int a[200005],ans[200005];
typedef struct node{
    int op;
    int idx;
}Node;
Node Ns[200005];
Node Stack[200005];
int top = 0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int Max_idx = 0;
    for(int i=0;i<m;i++) {
        cin>>Ns[i].op>>Ns[i].idx;
        if(Ns[i].idx > Max_idx){
            Max_idx = Ns[i].idx; //找出要操作的最大的下标
        }
    }
    for(int i=Max_idx+1;i<=n;i++) ans[i] = a[i]; //将后面可能不用改变的顺序直接赋值给ans数组
    sort(a+1,a+Max_idx+1);  //将最大下表之前的元素全部排序
    

    for(int i=0;i<m;i++){  //维护一个单调递减栈
        while(top>0 && Stack[top - 1].idx < Ns[i].idx) top --;
        Stack[top++] = Ns[i];
    }

    //cout<<Stack[top-1].idx<<endl;
    int l = 1,r = Max_idx;  //l , r 左右游标
    for(int j=0;j<top-1;j++){ //从栈底开始遍历，栈底的元素idx最大
        if(Stack[j].op==1){
            for(int i=Stack[j].idx;i>Stack[j+1].idx;i--){
                ans[i] = a[r];
                r--;
            }
        }
        else if (Stack[j].op==2){
            for(int i=Stack[j].idx;i>Stack[j+1].idx;i--){
                ans[i] = a[l];
                l++;
            }

        }
    }


    if(Stack[top-1].op==1){
        for(int i=Stack[top-1].idx;i>=1;i--){
            ans[i] = a[r];
            r--;
        }
    }
    else if (Stack[top-1].op==2){
        for(int i=Stack[top-1].idx;i>=1;i--){
            ans[i] = a[l];
            l++;
        }
    }


    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}
/*
Input
3 1
1 2 3
2 2
Output
2 1 3 
Input
4 2
1 2 4 3
2 3
1 2
Output
2 4 1 3 
*/