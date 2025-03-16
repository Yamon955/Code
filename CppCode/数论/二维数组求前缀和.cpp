#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N=6;
int f[6][6];//f[i][j]--->(0,0)->(i,j)区域的二维矩阵中的元素值的和即前缀和
int a[6][6];//地图
int main()
{
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++) cin>>a[i][j];//下标规定从1开始
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];//求前缀和公式->可参考概率论求概率的某个公式
    
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    ///////////////////////////求任意两点之间区域矩阵内的元素值的和
    int x1,x2,y1,y2;//(x1,y1)在(x2,y2)的左上角
    cin>>x1>>y1>>x2>>y2;
    int ans=f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1];
    cout<<ans<<endl;

    return 0;  
}
/*
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
*/