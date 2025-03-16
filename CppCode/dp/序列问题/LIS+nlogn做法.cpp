//https://blog.csdn.net/lxt_Lucia/article/details/81206439  -->LIS 三种做法
//O(n^2)的DP，O(nlogn)的二分+贪心法，以及O(nlogn)的树状数组优化的DP。

//贪心+二分--->O(nlogn)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e3+5;
int low[N]; //low [i]表示长度为 i 的 LIS 结尾元素的最小值
//对于一个上升子序列，显然其结尾元素越小，越有利于在后面接其他的元素，也就越可能变得更长 ---- 贪心
//对于每一个a[i]，如果a[i] > low [当前最长的LIS长度]，就把 a[i]接到当前最长的LIS后面，即low [++当前最长的LIS长度] = a [i]。
//对于每一个a [ i ]，如果a [ i ]能接到 LIS 后面，就接上去；否则，就用 a [ i ] 取更新 low 数组
//具体方法是，在low数组中找到第一个大于等于a [ i ]的元素low [ j ]，用a [ i ]去更新 low [ j ]。
//如果从头到尾扫一遍 low 数组的话，时间复杂度仍是O(n^2)。我们注意到 low 数组内部一定是单调不降的，
//所以我们可以二分 low 数组，找出第一个大于等于a[ i ]的元素。二分一次 low 数组的时间复杂度的O(lgn)，
//所以总的时间复杂度是O(nlogn)。
//POJ-2533
int n;
int a[N];
int Binary_Search(int l,int r,int x)  //二分查找
{
    while(l < r){
        int mid = (l+r)>>1;
        if(low[mid] < x) l = mid+1;
        else r = mid;
    }
    return l;
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) cin>>a[i];
    
        low[1] = a[1]; //初始化
        int len = 1;
        for(int i=2;i<=n;i++){
            if(a[i] > low[len]){  //如果这里的 if 条件改成 a[i] >= low[len] 就变成了求最长不下降子序列
                low[++len] = a[i];
            }
            else{
                //当然查找位置的时候也可以使用 lower_bound() 函数
                //int pos = lower_bound(low+1,low+len+1,a[i]) - low;
                int pos = Binary_Search(1,len,a[i]);  //找到 low[1]~low[len] 中第一个大于 a[i] 的数的位置
                low[pos] = a[i];                     //然后将其替换成 a[i] ---->贪心
            }
        }
        cout<<len<<endl;
    }
}
/*
Sample Input
7
1 7 3 5 9 4 8
Sample Output
4
*/