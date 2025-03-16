#include<iostream>
using namespace std;
int n,m,a[1000001];
int partition(int p,int r)
{
    int i = p,j = r+1;
    int x = a[p];
    while(1){
        while(a[++i]<x&&i<r);
        while(a[--j]>x);
        if(i>=j) break;
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}
void quicksort(int p,int r)
{
    if(p<r){
        int q = partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    quicksort(0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}