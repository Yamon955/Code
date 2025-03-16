#include<iostream>
#include<cstdio>
using namespace std;
//                         高精
int f[5010][5010];// 用二维数组存储步数 f[k][个位] f[k][十位] f[k][百位]..........   -->以此达到高精目的            
                // f[k][j]  k表示到第k阶楼梯  j存储阶数
int len=1;
int main()
{
    int n;
    cin>>n;
    for(int k=1;k<=n;k++){
        if(k==1) f[k][1]=1;
        else if(k==2) f[k][1]=2;
        else {
            for(int j=1;j<=len;j++)
            f[k][j]=f[k-1][j]+f[k-2][j];//f[k][j]表示
        }
        for(int i=1;i<=len;i++){
            if(f[k][i]>=10){ //满十向前一位进一
                f[k][i+1]+=f[k][i]/10;
                f[k][i]=f[k][i]%10;//自身取余
                if(f[k][len+1]) len++;//判断len是否要加一
            }
        }
    }
    for(int i=len;i>=1;i--) cout<<f[n][i];//逆序输出
    return 0;
}