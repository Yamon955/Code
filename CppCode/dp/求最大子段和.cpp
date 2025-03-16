#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100];
int n;//n个整数
///////////////////////////////////////////
int Max_sum(int n,int a[],int& best_i,int& best_j)//暴力求解————>O(n^3)
{
    int thissum=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int sum=0;
            for(int k=i;k<=j;k++)
                sum+=a[k];
            if(thissum<sum) {
                thissum=sum;
                best_i=i;
                best_j=j;
            }
        }
    }
    return thissum;
}
//改进暴力算法
int Max_sum2(int n,int a[],int& best_i,int& best_j)//----->O(n^2)
{
    int thissum=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=i;j<=n;j++){
            sum+=a[j];
            if(thissum<sum) {
                thissum=sum;
                best_i=i;
                best_j=j;
            }
        }
    }
    return thissum;
}
//继续改进算法-->分治法
/*
如果将所给的序列a[1:n]分为长度相等的两段a[1:n/2]和a[n/2+1:n]，分别求出这两段的最大子段和，则a[1:n]的最大子段和有三种情形：
a[1:n]的最大子段和与a[1:n/2]的最大子段和相同；
a[1:n]的最大子段和与a[n/2+1:n]的最大子段和相同；
a[1:n]的最大子段和为下面的形式。
A、B这两种情形可递归求得。对于情形C，容易看出，a[n/2]与a[n/2+1]在最优子序列中。因此，我们可以在a[1:n/2]和a[n/2+1:n]中分别计算出如下的s1和s2。则s1+s2即为出现情形C使得最优值
*/
//maxsum == max(left_sum,rights_sum,mid_sum)
int MaxSubSum(int l,int r)//分治法---->O(nlogn)
{
    int sum=0;
    if(l == r) sum=a[l]>0?a[l]:0;//如果只有一个整数，如果他为正数，则sum=这个正数，若它为负数，则sum=0；
    else{
        int mid=(l+r)>>1;
        int l_sum=MaxSubSum(l,mid);//求左部分的最大段和
        int r_sum=MaxSubSum(mid+1,r);//求右部分的最大段和

        int mid_sum_left=0;   //求中间部分的最大段和
        int lefts=0;
        for(int i=mid;i>=l;i--) {  
            lefts+=a[i];
            if(lefts>mid_sum_left)  mid_sum_left=lefts;
        }
        int mid_sum_right=0;
        int rights=0;
        for(int i=mid+1;i<=r;i++) {
            rights+=a[i];
            if(rights>mid_sum_right)  mid_sum_right=rights;
        }
        sum=mid_sum_left+mid_sum_right;//求出中间部分的最大段和并赋值给sum
        if(sum<l_sum) sum=l_sum;//比较三者大小
        if(sum<r_sum) sum=r_sum;
    }
    return sum;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
bj表示从a1到aj(前 j 项)中，包含aj的最大的子段和
由bj的定义易知，当bj-1>0 时bj=bj-1+aj，否则bj=aj。由此可得计算bj的动态规划递归式bj=max{bj-1+aj，aj}，1≤j≤n。
*/
int dp_MaxSubSum(int l,int r)//dp求最大子段和----->O(n)
{
    int sum=0,b=0;
    for(int i=l;i<=r;i++){
        if(b>0) b+=a[i];
        else  b=a[i];
        if(b>sum) sum=b;
    }
    return sum;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    cout<<"输入整数个数:";
    cin>>n;
     cout<<"依次输入整数:";
    for(int i=1;i<=n;i++) cin>>a[i];
    int i,j;
    cout<<"暴力法求解最大和:"<<Max_sum(n,a,i,j)<<endl;
    cout<<"优化暴力法求解最大和:"<<Max_sum2(n,a,i,j)<<endl;
    cout<<"分治法求解最大和:"<<MaxSubSum(1,n)<<endl;
    cout<<"dp求解最大和:"<<dp_MaxSubSum(1,n)<<endl;
    return 0;

}
/*
输入：
6
-2 11 -4 13 -5 -2
->20;
*/