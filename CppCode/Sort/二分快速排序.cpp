#include<iostream>
using namespace std;
int n,m,a[1000001];
void qsort(int l,int r)//Ӧ�ö���˼��
{
    int mid=a[(l+r)/2];//�м���
    int i=l,j=r;
    do{
        while(a[i]<mid) i++;//������벿�ֱ��м��������
        while(a[j]>mid) j--;//�����Ұ벿�ֱ��м���С����
        if(i<=j)//�����һ�鲻����������������С�Ҵ󣩵���
        {
            swap(a[i],a[j]);//����
            i++;
            j--;
        }
    }while(i<=j);//����ע��Ҫ��=
    if(l<j) qsort(l,j);//�ݹ�������벿��
    if(i<r) qsort(i,r);//�ݹ������Ұ벿��
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++) cin>>a[i];
    qsort(1,n);
    cout<<a[n+1];
}
