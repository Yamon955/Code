#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
set<int>a;//集合中元素都是有序排列的
int main()
{
    /*
    a.insert()//插入  
    a.begin()//返回set容器的第一个元素迭代器
    a.end()//返回a的最后一个元素迭代器
    a.clear()//清空
    a.empty()//判断是否为空
    a.max_size()//返回a可能包含的元素的最大个数
    a.size()//返回元素个数
    a.erase(iterator)//删除定位器iterator指向的值
    a.erase(first,second)//删除定位器first和second之间的值
    a.erase(key)//删除元素值等于key的元素
    a.find(key)//返回等于key值的定位器，若没有找到则返回a.end()的值
    */
    a.insert(1);
    a.insert(2);
    a.insert(8);
    a.insert(4);
    a.insert(1);
    a.insert(4);
    cout<<"set 的 size 值为 ："<<a.size()<<endl;
    //cout<<"set 的 maxsize的值为 ："<<a.max_size()<<endl;
    cout<<"set 中的第一个元素是 ："<<*a.begin()<<endl;
    cout<<"set 中的最后一个元素是:"<<*a.end()<<endl;
    a.clear();
    if(a.empty()){
        cout<<"set为空！！！"<<endl;
    }
    cout<<"set 的 size 值为 ："<<a.size()<<endl;
    //cout<<"set 的 maxsize的值为 ："<<a.max_size()<<endl;
    set<int>::const_iterator iter;
    set<int>::iterator first;
    set<int>::iterator second;
    for(int i=1;i<=10;i++) a.insert(i);
    a.insert(99);
    a.insert(11);
    a.erase(a.begin());//删除第一个元素
    first=a.begin();
    second=a.begin();
    second++;
    second++;
    a.erase(first,second);//删除first和second之间的元素
    a.erase(9);//删除值为9的元素
    for(iter = a.begin();iter!=a.end();iter++){
        cout<<*iter<<endl;
    }
    int b[]={8,2,5,6,7};  //set会自动排序
    set<int>s(b,b+5);
    set<int>::iterator iter2; 
    for(iter2 = s.begin();iter2!=s.end();iter2++){
        cout<<*iter2<<endl;
    }
    return 0;


}