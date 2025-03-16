#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char x[100],y[100];//两个字符串
int m[100][100];//m[i][j]表示 x[0]~x[i] 与 y[0]~y[j] 的最长公共子序列的长度
int v[100][100];//记录m[i][j]从那个式子求来的，用来输出最长公共子序列
/*
思想：
设序列X={x1,x2,…,xm}和Y={y1,y2,…,yn}的最长公共子序列为Z={z1,z2,…,zk} ，则
(1)若xm=yn,则zk=xm=yn，且Zk-1是Xm-1和Yn-1的最长公共子序列。
(2)若xm≠yn且zk≠xm，则Z是xm-1和Y的最长公共子序列。
(3)若xm≠yn且zk≠yn，则Z是X和yn-1的最长公共子序列。
其中： Xm-1={x1,x2,…,xm-1}；Yn-1={y1,y2,…,yn-1} ；Zk-1={z1,z2,…,zk-1} 
*/
/*
     dp初始条件： m[0][i]=m[i][0]=0                 i<=n;
     dp方程   ：m[i][j]=m[i-1][j-1]+1               x[i]==y[j]
                m[i][j]=max(m[i-1][j],m[i][j-1])   x[i]!=y[j]
*/
void LCSLength(int l,int r)//动态规划求法
{
    for(int i=1;i<=l;i++) m[i][0]=0;
    for(int i=1;i<=r;i++) m[0][i]=0;
    for(int i=1;i<=l;i++)
        for(int j=1;j<=r;j++){
            if(x[i]==y[j]){
                m[i][j]=m[i-1][j-1]+1;
                v[i][j]=1;
            } 
            else if(m[i-1][j]>=m[i][j-1]) {
                m[i][j]=m[i-1][j];
                v[i][j]=2;
            }
            else  {
                m[i][j]=m[i][j-1];
                v[i][j]=3;
            }
        }
}
void LCS(int i,int j)//利用数组 v[][] 求出最长公共子序列
{
    if(i == 0 || j == 0) return;
    if(v[i][j] == 1){
        LCS(i-1,j-1);
        cout<<x[i];
    }
    else if(v[i][j] == 2) LCS(i-1,j);
    else   LCS(i,j-1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int _max(int x,int y)
{
    return x>y?x:y;
}
int RecurLCSLength(int l,int r)//递归
{
    if(l==0 || r==0) return 0;
    if(x[l]==y[r]) return RecurLCSLength(l-1,r-1)+1;
    else return _max(RecurLCSLength(l-1,r),RecurLCSLength(l,r-1));
}
int main()
{
    cin>>x>>y;//规定字符串第0位为特殊字符不参与求最大公共子序列过程
    int xlen=strlen(x)-1;
    int ylen=strlen(y)-1;
    cout<<"递归求出的最长公共子序列的长度:"<<RecurLCSLength(xlen,ylen)<<endl;//输出递归求出的最长公共子序列的长度
    LCSLength(xlen,ylen);
    cout<<"dp求出的最长公共子序列的长度:"<<m[xlen][ylen]<<endl;
    cout<<"dp求出的最长公共子序列为:";
    LCS(xlen,ylen);
    cout<<endl;
    cout<<"矩阵m:"<<endl;
    for(int i=0;i<=xlen;i++){
        for(int j=0;j<=ylen;j++) cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<"矩阵v:"<<endl;
    for(int i=0;i<=xlen;i++){
        for(int j=0;j<=ylen;j++) cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/*
输入： 
*abcbdab
*bdcaba
*/