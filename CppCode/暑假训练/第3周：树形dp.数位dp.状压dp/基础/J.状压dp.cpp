//POJ2411
//https://blog.csdn.net/u014634338/article/details/50015825 题解分析不错
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int h,w;
ll dp[12][1<<12];
//设置初始状态
//判断上一次状态和本次状态是否兼容 
//当前列 j 如果为 1 ，   (1)  如果当前列为最后一列，则此状态不可行，返回 false;
//                      (2)必须保证下一列即 j+1 列为 1，表示横放一块，然后直接跳过该两列(j+=2),-->去判断第 j+2 列
//                      (3)如果下一列即 j+1 列为 0 ，则该状态不满足，即该状态不可行，返回 false;
//当前列 j 如果为 0 ， 则表示在该列竖直放置一块，然后去判断第 j+1 列

bool init(int st)
{
    for(int j=0;j<w;){     //前j-1列符合要求，对第j列进行判断
        if(st & (1<<j)){   //第j列为1
            if(j==w-1)     //j为最后一列，不可行
                return false;
            if(st & (1<<(j+1))) j+=2;  //第j列和第j+1列都为1 则表示横放，可行，考虑 j+2列
            else return false;        //第j列为1，第j+1列都为0不可行
        } 
        else j++;   //第j列为0 ，则为竖放，可行
    }
    return true;  //该状态满足，可行
}
bool check(int pos,int pre)
{
    for(int j=0;j<w;){
        if(pos & (1<<j)){       //第i行第j列为1
            if(pre & (1<<j)){  //第i-1行第j列也为1，那么第i行必然是横放
                //第i行和第i-1行的第j+1都必须是1，否则是非法的
                if(j==w-1 || !(pos & 1<<(j+1)) || !(pre & 1<<(j+1)))
                    return false;
                else j+=2;
            }
            else j++;  //第i-1行第j列为0，说明第i行第j列是竖放
        }
        else{     //第i行第j列为0，那么第i-1行的第j列应该是已经填充了的
            if(pre & (1<<j)) j++;
            else return false;
        }
    }
    return true;
}
int main()
{
    while(scanf("%d%d",&h,&w)){
        if(h==0 && w==0) break;
        if(((h*w) & 1 )== 1) printf("0\n");  //n和m均为奇数的话，矩形面积就是奇数，可知是不可能完全覆盖的
        else{
            //因为算法 复杂度是  H * (W^4) 所以当 W > H的时候，我们交换他们这样适当降低复杂度。
            if(h<w){      //交换h和w使h较大w较小，这样能减少状态数
                int t = h;
                h = w;
                w = t;
            }
            int tol = (1<<w)-1;
            memset(dp,0,sizeof dp);
            for(int s=0;s<=tol;s++){
                if(init(s)) 
                    dp[1][s] = 1;  //按状态 s 值放置第一行可行，则赋值为1
            }
            for(int i=2;i<=h;i++){      //按行dp
                for(int j=0;j<=tol;j++){     //第i行的状态
                    for(int k=0;k<=tol;k++){     //第i-1行的状态
                        if(check(j,k)) dp[i][j] += dp[i-1][k];
                    }
                }
            }
            printf("%lld\n",dp[h][tol]);

        }

    }
    return 0;
}
/*
示例输入
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
样本输出
1
0
1
2
3
5
144
51205
*/