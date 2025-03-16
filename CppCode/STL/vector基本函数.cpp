#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int>a,f;//声明了一个int型的不定长数组a和f        类似于int a[],int f[]
vector<double>b;//声明了一个double型的不定长数组b  类似于double b[]
vector<string>c;//声明了一个string型的不定长数组c 类似于string c[]
vector<int>d[100];//声明了一个二维数组d[100][];
int main()
{
    /*
    a.insert()//看代码最后
    a.size();//读取数组a的大小
    a.resize();//改变数组a的大小
    a.push_back();//向尾部添加元素
    a.pop_back();//删除最后一个元素  没有返回值
    a.clear();//清空
    a.empty();//判断是否为空
    vector数组之间可以之间赋值或者作为函数的返回值，如vector<int>a,b;  a=b;//合法
    */
   for(int i=0;i<10;i++){
       a.push_back(i);
   }
   cout<<"数组长度:"<<a.size()<<endl;
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
    v[3]=5;//此时v为2 7 9 5
    v.insert(v.begin(),8);//在最前面插入新元素,此时v为8 2 7 9 5
    v.insert(v.begin()+3,1);//在迭代器中下标为3的元素前插入新元素,此时v为8 2 7 1 9 5
    v.insert(v.end(),3);//在向量末尾追加新元素,此时v为8 2 7 1 9 5 3
    v.insert(v.end(),3,0);//在尾部插入3个0,此时v为8 2 7 1 9 5 3 0 0 0
    
    int a[] = {1,2,3,4};
    v.insert(v.end(),a[2],a[1]);//在尾部插入a[2]个a[1],此时v为8 2 7 1 9 5 3 0 0 0 2 2 2
    
    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
   return 0;

}
