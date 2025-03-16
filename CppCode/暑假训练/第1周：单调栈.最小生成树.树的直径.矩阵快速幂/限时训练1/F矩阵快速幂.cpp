//51Nod 1126
//  1 //mod运算与%运算是有区别的，这也是这题的一个坑：
//  2 //mod运算得到的数一定是非负数，而%则不一定
//  3 //所以在最终结果小于0时，累加7直到非负
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef struct Node{
    int m[2][2];
}Matrix;
int a,b,n;
Matrix mul(Matrix A,Matrix B){
    Matrix ans;
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++){
        ans.m[i][j]=0;
        for(int k=0;k<2;k++){
            ans.m[i][j]+=A.m[i][k]*B.m[k][j];
            ans.m[i][j]%=7;
        }
    }
    return ans;
}//矩阵乘法
Matrix qsm(Matrix a,int b){
    Matrix ans;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++) ans.m[i][j] = 0;
    }
    for(int i=0;i<2;i++) ans.m[i][i] = 1; //单位矩阵
    while(b){
        if(b&1) ans = mul(ans,a);
        b>>=1;
        a = mul(a,a);
    }
    return ans;
}
int main()
{
    cin>>a>>b>>n;
    Matrix tmp;
    tmp.m[0][0] = a;
    tmp.m[0][1] = 1;
    tmp.m[1][0] = b;
    tmp.m[1][1] = 0;
    Matrix ans = qsm(tmp,n-2);
    Matrix B;
    B.m[0][0] = B.m[0][1] = 1;
    B.m[1][0] = B.m[1][1] = 0;
    B = mul(B,ans);
    //cout<<(B.m[0][0]%7+7)%7;  //防止出现负数
    while(B.m[0][0]<0) B.m[0][0] += 7;
    cout<<B.m[0][0];
    return 0;

}