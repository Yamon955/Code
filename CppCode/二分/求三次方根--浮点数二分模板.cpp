#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double n;
//浮点数二分模板
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
///////////////////////////////////////////////////////////////////////////////////////////////
/*
AC wing---790
给定一个浮点数 n，求它的三次方根。
注意，结果保留 6 位小数。

数据范围
−10000≤n≤10000
输入样例：
1000.00
输出样例：
10.000000
*/
int main()
{
    cin>>n;
    double l=-10000,r=10000;//二分范围由题目确定
    while(r-l>1e-7){ //1e-8,1e-9都行(由题目确定)
        double mid=(l+r)/2;
        if(mid*mid*mid-n<0) l=mid;//不要用l=mid+0.0000001当为求负数的三次方根的时候错误
        else r=mid;
        /*
        if(mid*mid*mid-n>0) r=mid;
        else l=mid;
        */
    }
    printf("%.6f",l);
    return 0;
}