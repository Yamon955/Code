#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int>a,f;//������һ��int�͵Ĳ���������a��f        ������int a[],int f[]
vector<double>b;//������һ��double�͵Ĳ���������b  ������double b[]
vector<string>c;//������һ��string�͵Ĳ���������c ������string c[]
vector<int>d[100];//������һ����ά����d[100][];
int main()
{
    /*
    a.insert()//���������
    a.size();//��ȡ����a�Ĵ�С
    a.resize();//�ı�����a�Ĵ�С
    a.push_back();//��β�����Ԫ��
    a.pop_back();//ɾ�����һ��Ԫ��  û�з���ֵ
    a.clear();//���
    a.empty();//�ж��Ƿ�Ϊ��
    vector����֮�����֮�丳ֵ������Ϊ�����ķ���ֵ����vector<int>a,b;  a=b;//�Ϸ�
    */
   for(int i=0;i<10;i++){
       a.push_back(i);
   }
   cout<<"���鳤��:"<<a.size()<<endl;
   if(!a.empty()) {
       for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
   }
   a.pop_back();
   if(!a.empty()) {
       for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
   }

    vector<int> v(4);
    v[0]=2;
    v[1]=7;
    v[2]=9;
    v[3]=5;//��ʱvΪ2 7 9 5
    v.insert(v.begin(),8);//����ǰ�������Ԫ��,��ʱvΪ8 2 7 9 5
    v.insert(v.begin()+3,1);//�ڵ��������±�Ϊ3��Ԫ��ǰ������Ԫ��,��ʱvΪ8 2 7 1 9 5
    v.insert(v.end(),3);//������ĩβ׷����Ԫ��,��ʱvΪ8 2 7 1 9 5 3
    v.insert(v.end(),3,0);//��β������3��0,��ʱvΪ8 2 7 1 9 5 3 0 0 0
    
    int a[] = {1,2,3,4};
    v.insert(v.end(),a[2],a[1]);//��β������a[2]��a[1],��ʱvΪ8 2 7 1 9 5 3 0 0 0 2 2 2
    
    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
   return 0;

}
