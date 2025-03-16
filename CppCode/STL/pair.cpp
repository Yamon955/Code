#include<iostream>
#include<cstdio>
#include<cstring>
#include<utility>//pair标准库所在头文件
#include<vector>
using namespace std;
//#define PII pair<int,int>   简写
//#define PSI pair<string,int>
//#define x first  //简写first
//#define y second
int main()
{
    pair<int,string>p1;//使用默认的构造函数
    pair<int,double>p2(1,2.4);//用给定值初始化
    pair<int,double>p3(p2);//拷贝构造函数
    pair<string,string>p6("jdbv","advb");
    //通过pair的两个公有函数first和second来访问两个元素
    p1.first=1;
    p1.second="jdjnv";
    cout<<"p1("<<p1.first<<","<<p1.second<<")"<<endl;

    //赋值
    pair<int,double>p4=p2;//变量间的赋值
    cout<<"p4("<<p4.first<<","<<p4.second<<")"<<endl;
    p4=make_pair(4,5.8);
    cout<<"p4("<<p4.first<<","<<p4.second<<")"<<endl;

    //可以使用make_pair对已存在的两个数据构造一个新的pair类型
    int a=1;
    string b="tom";
    pair<int,string>p5;
    p5=make_pair(a,b);
    //由于pair类型的使用比较繁琐，因为如果要定义多个形同的pair类型的时候，可以时候typedef简化声明
    typedef pair<string,string>author;
    author p7("May","Lily");
    author p8("James","Joy");



    typedef vector<pair<string,int>>VP;
    VP vp;
    vp.push_back(make_pair("tom",18));
    vp.push_back(make_pair("May",19));
    VP::iterator it;//定义迭代器
    for(it=vp.begin();it!=vp.end();it++)
        cout<<it->first<<","<<it->second<<endl;
    return 0;

}