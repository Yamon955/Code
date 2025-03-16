#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
//#include<unordered_map>
//unordered_map<string>s;//定义
//unordered_map -->map的进阶版，搜寻值时比map快---->O(1)
//因为map在插入时会自动排序，故搜寻map[s]值时------->O(logn)
//map是STL的一个关联容器，他提供一对一的Hash
//第一个可以称为关键字(key)，每个关键字只能在map中出现一次
//第二个可能称为该关键字的值(value)；一对一
//Map 中的元素是自动按 key 升序排序,所以不能对 map 用 sort 函数：
/*
    count()        count(s),如果s不在在map中，返回0，否则返回插入s的位序
    insert()          插入，会覆盖重复的
    begin()                  返回指向 map 头部的迭代器
    clear(）                 删除所有元素
    empty()                 如果 map 为空则返回 true
    size()                    返回map中元素的个数
    a.swap(b)  swap(a,b)                 交换两个map
*/
int main()
{
    //插入
    map<int,string>mapStu;//定义一个对象
    // 第一种 用insert函数插入pair
    mapStu.insert(pair<int,string>(1,"May"));
    //insert 函数插入 value_type 数据
    mapStu.insert(map<int,string>::value_type(2,"Tom"));
    //用数组方式插入数据
    mapStu[3]="Jerry";
    //迭代器遍历
    map<int,string>::iterator it;
    for(it=mapStu.begin();it!=mapStu.end();it++)
        cout<<it->first<<","<<it->second<<endl;
    //数组形式遍历
    for(int i=1;i<=mapStu.size();i++)
        cout<<i<<","<<mapStu[i]<<endl;

    ///Map 中的元素是自动按 key 升序排序
   map < int, int > m1;
   map < int, int >::iterator m1_Iter;
   m1.insert ( pair < int, int >  ( 1, 20 ) );
   m1.insert ( pair < int, int >  ( 4, 40 ) );
   m1.insert ( pair < int, int >  ( 3, 60 ) );
   m1.insert ( pair < int, int >  ( 2, 50 ) );
   m1.insert ( pair < int, int >  ( 6, 40 ) );
   m1.insert ( pair < int, int >  ( 7, 30 ) );
   cout << "The original map m1 is:"<<endl;
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout <<  m1_Iter->first<<" "<<m1_Iter->second<<endl;
    return 0;
}
