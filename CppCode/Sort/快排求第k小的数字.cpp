//P1923
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,k;
int a[5000005];
void quicksort(int l,int r)
{
    int i=l,j=r,mid=a[(l+r)/2];
    do{
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j){
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
            i++;
            j--;
        }
    }while(i<=j);
    ////快排后数组被划分为三块： l<=j<=i<=r
    if(k<=j) quicksort(l,j);//在左区间只需要搜左区间
    else if(i<=k) quicksort(i,r);//在右区间只需要搜右区间
    else {   //如果在中间区间直接输出
        printf("%d",a[k]);
        exit(0);
    }
}
int main()
{
    cin>>n>>k;
    k = k-1;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    quicksort(0,n-1);
    return 0;
}
/*
Simple input：
4 2
1 5 4 12
Simple output：
4
*/