#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/////////算法设计与分析课本例题（动态规划）
const int n=6;//矩阵的个数
int p[7];//存放六个矩阵的维度  矩阵A1=p[0]*p[1]维，A2=p[1]*p[2]维，依次类推，A6=p[5]*p[6]维
int m[100][100];//m[i][j]从表示第i个矩阵Ai乘到第j个矩阵Aj所需要的相乘的次数
int s[100][100];
///////////////////////////////////////////////////////////////////////////////////////////////////
/* dp初始条件  m[i][j] = 0 (i==j);
   dp方程     m[i][j] = m[i][k]+m[k+1][j]+p[i]*p[k]*p[j];
   */
void MatrixChain(int p[],int n,int m[][100],int s[][100])//非递归求法(动态规划)（自底向上运算）
{
    for(int i=1;i<=n;i++) m[i][i]=0;
    for(int r=1;r<=n-1;r++){
         for(int i=1;i<=n-r;i++){
             int j=i+r;
             m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
             s[i][j]=i;
            for(int k=i+1;k<j;k++){
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j]) {
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
         }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*递归方程    m[i][j] = 0                                      i=j;
                     = min(m[i][k]+m[k+1][j])+p[i]*p[k]*p[j]  i<j;
 */
int RecurMatrixChain(int i,int j)//递归求矩阵Ai乘到Aj所需要的最少次数（自上向下运算）
{
    if(i==j) return 0;
    int u=RecurMatrixChain(i,i)+RecurMatrixChain(i+1,j)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++){
        int t=RecurMatrixChain(i,k)+RecurMatrixChain(k+1,j)+p[i-1]*p[k]*p[j];
        if(t<u){
            u=t;
            s[i][j]=k;
        }
    }
    return u;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int LoockupChain(int i,int j)
{
    if(m[i][j]>0) return m[i][j];//记忆化
    if(i==j) return 0;
    int u=LoockupChain(i,i)+LoockupChain(i+1,j)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++){
        int t=LoockupChain(i,k)+LoockupChain(k+1,j)+p[i-1]*p[k]*p[j];
        if(t<u){
            u=t;
            s[i][j]=k;
        }
    }
    m[i][j]=u;
    return u;
}

int MemorizeMatrixChain(int n)//记忆化递归求矩阵Ai乘到Aj所需要的最少次数，可减少重复计算
{
     for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) m[i][j]=0;
    return LoockupChain(1,n);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Traceback(int i,int j,int s[][100])
{
    if(i==j) return;
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    cout<<"Multiply A "<<i<<","<<s[i][j];
    cout<<" and A "<<(s[i][j]+1)<<","<<j<<endl;

}
int main()
{
    p[0]=30;
    p[1]=35;
    p[2]=15;
    p[3]=5;
    p[4]=10;
    p[5]=20;
    p[6]=25;
    //MatrixChain(p,n,m,s);
    //RecurMatrixChain(1,n);
     MemorizeMatrixChain(n);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) cout<<m[i][j]<<" ";
    cout<<endl;
    Traceback(1,6,s);
    return 0;

}