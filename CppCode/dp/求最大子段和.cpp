#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100];
int n;//n������
///////////////////////////////////////////
int Max_sum(int n,int a[],int& best_i,int& best_j)//������⡪������>O(n^3)
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
//�Ľ������㷨
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
//�����Ľ��㷨-->���η�
/*
���������������a[1:n]��Ϊ������ȵ�����a[1:n/2]��a[n/2+1:n]���ֱ���������ε�����Ӷκͣ���a[1:n]������Ӷκ����������Σ�
a[1:n]������Ӷκ���a[1:n/2]������Ӷκ���ͬ��
a[1:n]������Ӷκ���a[n/2+1:n]������Ӷκ���ͬ��
a[1:n]������Ӷκ�Ϊ�������ʽ��
A��B���������οɵݹ���á���������C�����׿�����a[n/2]��a[n/2+1]�������������С���ˣ����ǿ�����a[1:n/2]��a[n/2+1:n]�зֱ��������µ�s1��s2����s1+s2��Ϊ��������Cʹ������ֵ
*/
//maxsum == max(left_sum,rights_sum,mid_sum)
int MaxSubSum(int l,int r)//���η�---->O(nlogn)
{
    int sum=0;
    if(l == r) sum=a[l]>0?a[l]:0;//���ֻ��һ�������������Ϊ��������sum=�������������Ϊ��������sum=0��
    else{
        int mid=(l+r)>>1;
        int l_sum=MaxSubSum(l,mid);//���󲿷ֵ����κ�
        int r_sum=MaxSubSum(mid+1,r);//���Ҳ��ֵ����κ�

        int mid_sum_left=0;   //���м䲿�ֵ����κ�
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
        sum=mid_sum_left+mid_sum_right;//����м䲿�ֵ����κͲ���ֵ��sum
        if(sum<l_sum) sum=l_sum;//�Ƚ����ߴ�С
        if(sum<r_sum) sum=r_sum;
    }
    return sum;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
bj��ʾ��a1��aj(ǰ j ��)�У�����aj�������Ӷκ�
��bj�Ķ�����֪����bj-1>0 ʱbj=bj-1+aj������bj=aj���ɴ˿ɵü���bj�Ķ�̬�滮�ݹ�ʽbj=max{bj-1+aj��aj}��1��j��n��
*/
int dp_MaxSubSum(int l,int r)//dp������Ӷκ�----->O(n)
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
    cout<<"������������:";
    cin>>n;
     cout<<"������������:";
    for(int i=1;i<=n;i++) cin>>a[i];
    int i,j;
    cout<<"�������������:"<<Max_sum(n,a,i,j)<<endl;
    cout<<"�Ż��������������:"<<Max_sum2(n,a,i,j)<<endl;
    cout<<"���η��������:"<<MaxSubSum(1,n)<<endl;
    cout<<"dp�������:"<<dp_MaxSubSum(1,n)<<endl;
    return 0;

}
/*
���룺
6
-2 11 -4 13 -5 -2
->20;
*/