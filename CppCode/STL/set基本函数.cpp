#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
set<int>a;//������Ԫ�ض����������е�
int main()
{
    /*
    a.insert()//����  
    a.begin()//����set�����ĵ�һ��Ԫ�ص�����
    a.end()//����a�����һ��Ԫ�ص�����
    a.clear()//���
    a.empty()//�ж��Ƿ�Ϊ��
    a.max_size()//����a���ܰ�����Ԫ�ص�������
    a.size()//����Ԫ�ظ���
    a.erase(iterator)//ɾ����λ��iteratorָ���ֵ
    a.erase(first,second)//ɾ����λ��first��second֮���ֵ
    a.erase(key)//ɾ��Ԫ��ֵ����key��Ԫ��
    a.find(key)//���ص���keyֵ�Ķ�λ������û���ҵ��򷵻�a.end()��ֵ
    */
    a.insert(1);
    a.insert(2);
    a.insert(8);
    a.insert(4);
    a.insert(1);
    a.insert(4);
    cout<<"set �� size ֵΪ ��"<<a.size()<<endl;
    //cout<<"set �� maxsize��ֵΪ ��"<<a.max_size()<<endl;
    cout<<"set �еĵ�һ��Ԫ���� ��"<<*a.begin()<<endl;
    cout<<"set �е����һ��Ԫ����:"<<*a.end()<<endl;
    a.clear();
    if(a.empty()){
        cout<<"setΪ�գ�����"<<endl;
    }
    cout<<"set �� size ֵΪ ��"<<a.size()<<endl;
    //cout<<"set �� maxsize��ֵΪ ��"<<a.max_size()<<endl;
    set<int>::const_iterator iter;
    set<int>::iterator first;
    set<int>::iterator second;
    for(int i=1;i<=10;i++) a.insert(i);
    a.insert(99);
    a.insert(11);
    a.erase(a.begin());//ɾ����һ��Ԫ��
    first=a.begin();
    second=a.begin();
    second++;
    second++;
    a.erase(first,second);//ɾ��first��second֮���Ԫ��
    a.erase(9);//ɾ��ֵΪ9��Ԫ��
    for(iter = a.begin();iter!=a.end();iter++){
        cout<<*iter<<endl;
    }
    int b[]={8,2,5,6,7};  //set���Զ�����
    set<int>s(b,b+5);
    set<int>::iterator iter2; 
    for(iter2 = s.begin();iter2!=s.end();iter2++){
        cout<<*iter2<<endl;
    }
    return 0;


}