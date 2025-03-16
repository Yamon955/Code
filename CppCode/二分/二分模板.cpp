#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int q[1000];
int main()
{
    int l,r,x;
    //ģ��1   ������
    while(l < r){
        //int mid = l + (r - l) >> 1; ���Ա������
        int mid = l + r >> 1;
        if(q[mid] < x)   //[mid + 1 , r]
            l = mid + 1;
        else             //[l , mid]
            r = mid;
    }
    //ģ��2  ���ҵ���
    while(l < r){
        //int mid = l + (r - l + 1) >> 1; ���Ա������
        int mid = ( l + r + 1) >> 1;
        //�������1����mid=l+r>>1 ��ֻʣ��q[l],q[r]������(��r-l=1)ʱ,���������ǡ����q[l]�Ļ�,mid��һֱ����l������ѭ��
        //+1��Ŀ���Ǳ�����ѭ����������Ϊ l = mid ʱ��һ��Ҫ +1 ������ѭ��
        if(q[mid] > x)  //[l , mid - 1]
            r = mid - 1;
        else            //[mid , r]
            l = mid;
    }
    return 0;
}
/*
����ģ�������
����Ҫ���ҵ����ڱ������������ж��ʱ
--->ģ��1 �᷵�ش�����˳���һ�����ڲ�������λ��(��������С�±�)(���������������е�һ�γ���ʱ���±�λ��)
--->ģ��2 �᷵�ش��ҵ���˳���һ�����ڲ�������λ��(����������±�)(�������������������һ�γ���ʱ���±�λ��)
���磺a[]={0,0,0,0,0},���� x=0 ��Ԫ��ֵ�±�
--->ģ��1   ���� �±� 0
--->ģ��2   ���� �±� 4
*/

//���ֲ���ģ�壨���ֵ��С  ��Сֵ���
//��check��ǰ��mid�Ƿ�Ϸ����Ϸ���𰸿����ǵ�ǰ��Ҳ������ߣ���������ұߵ�������
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;//����������һλ�����������(l + r )/2
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    return l;
}

//��check��ǰ��mid�Ƿ�Ϸ����Ϸ���𰸿����ǵ�ǰ��Ҳ�����ұߣ����������ߵ�������
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
