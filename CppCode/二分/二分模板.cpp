#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int q[1000];
int main()
{
    int l,r,x;
    //模板1   从左到右
    while(l < r){
        //int mid = l + (r - l) >> 1; 可以避免溢出
        int mid = l + r >> 1;
        if(q[mid] < x)   //[mid + 1 , r]
            l = mid + 1;
        else             //[l , mid]
            r = mid;
    }
    //模板2  从右到左
    while(l < r){
        //int mid = l + (r - l + 1) >> 1; 可以避免溢出
        int mid = ( l + r + 1) >> 1;
        //如果不加1，即mid=l+r>>1 当只剩余q[l],q[r]两个数(即r-l=1)时,如果查找数恰好是q[l]的话,mid会一直等于l陷入死循环
        //+1的目的是避免死循环，当更新为 l = mid 时，一定要 +1 避免死循环
        if(q[mid] > x)  //[l , mid - 1]
            r = mid - 1;
        else            //[mid , r]
            l = mid;
    }
    return 0;
}
/*
两个模板的区别：
当当要查找的数在被查找序列中有多个时
--->模板1 会返回从左到右顺序第一个等于查找数的位置(即返回最小下标)(即查找数在数组中第一次出现时的下标位置)
--->模板2 会返回从右到左顺序第一个等于查找数的位置(即返回最大下标)(即查找数在数组中最后一次出现时的下标位置)
例如：a[]={0,0,0,0,0},查找 x=0 的元素值下标
--->模板1   返回 下标 0
--->模板2   返回 下标 4
*/

//二分查找模板（最大值最小  最小值最大）
//当check当前答案mid是否合法，合法则答案可能是当前数也可能左边，否则答案在右边的做法。
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;//二进制右移一位操作，相等于(l + r )/2
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    return l;
}

//当check当前答案mid是否合法，合法则答案可能是当前数也可能右边，否则答案在左边的做法。
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid;
    }
    return l;
}
