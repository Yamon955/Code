#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
///问题：n堆石子，每次只能有次序地将相邻的两堆合成新的一堆，并将新的一堆的石子数记为该次合并的得分，
///计算出最终合成一堆的最小和最大得分

int n;//堆数
int f[1010];//石子堆
int v[1010];//标记数组，用来标记该石子堆有没有已经被合并
///////////////////////////////////////////////////////////////////////////////////////
//求最大得分思想：先找出n堆石子中相加之和最大的相邻的两堆石子，并将他们合并成一堆，
//然后每次合并这个新形成的石子堆与它左右相邻中较大的石子堆(即每次合并相加之和最大的相邻的两堆石子)，最终得出最大堆数
int get_Max()//求最大分数
{
    int Max=-0x3f3f3f3f;
    int Max_t;
    for(int i=0;i<n;i++)
        if(f[i]>Max){ 
            Max = f[i];  //找出最大的石子堆
            Max_t = i;   //并记下下标
        }
    int sum = Max;
    int Max_sum = 0;
    int Max_left = (Max_t-1+n) % n; //找最大石子堆的左右两堆
    int Max_right = (Max_t+1) % n;
    v[Max_t] = 1;
    for(int i=0;i<n;i++){
        if(i<=n-2){
            while(v[Max_left])  Max_left = (--Max_left+n) % n;
            while(v[Max_right]) Max_right = (++Max_right) % n; 
            if(f[Max_left]>f[Max_right]) {
                sum += f[Max_left];
                Max_sum += sum;
                v[Max_left] = 1;
            }
            else {
                sum += f[Max_right];
                Max_sum += sum;
                v[Max_right] = 1;
            }
        }
        else {
            int j;
            for(j=0;j<n;j++) 
                if(!v[j]) break;
            sum += f[j];
            Max_sum += f[j]; 
        }
    }
    return Max_sum;//返回最大得分
}
///求最小得分思想：一共只需遍历n-1次，前n-2次只需求出相邻之和最小的两堆石子，
//然后加到总得分中并且将其中一堆石子数置为这个最小和，另一堆标记为已访问
int get_Min()
{
    memset(v,0,sizeof(v));//标记数组置0
    int Min_sum = 0;
    for(int k=1;k<n;k++){  //一共遍历n-1次
        if(k<=n-2){  //前n-2次，每次求出相邻两项和最小的值
            int Min = 0x3f3f3f3f;
            int num1,num2;
            for(int i=0;i<n;i++){
                if(v[i]==0){
                    int left = (i-1+n)%n;
                    int right = (i+1)%n;
                    while(v[left])  left = (left-1+n)%n;
                    while(v[right]) right = (right+1)%n;
                    if(f[left]>f[right]){
                        if(f[i]+f[right]<Min){
                            Min = f[i]+f[right];
                            num1 = i;
                            num2 = right;
                        }
                    }
                    else {
                        if(f[i]+f[left]<Min){
                            Min = f[i]+f[left];
                            num1 = i;
                            num2 = left;
                        }
                    }
                }
            }
            f[num1] = Min;//将相加之和最小的相邻两项其中一项值为相加的和，另一项标记为已访问
            Min_sum += Min;//得分相加
            v[num2] = 1;//标记为 1
        }
        else if(k==n-1){ //最后一次，石子堆只剩下两堆，只需将这两堆加到总的得分中即可
            for(int i=0;i<n;i++){
                if(v[i]==0){
                    Min_sum += f[i]; 
                }
            }
        }
        
    }
    return Min_sum;//返回最小得分
    
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    cout<<"最大得分为:"<<get_Max()<<endl;
    cout<<"最小得分为:"<<get_Min()<<endl;
    return 0;

}
/*
4 
4 4 5 9
*/