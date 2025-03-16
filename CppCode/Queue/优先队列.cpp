#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
/*
  优先队列容器和队列一样，只能从队尾插入元素，从队首删除元素。

      为什么能叫优先队列呢？？因为它有一个特性，就是队列中最大的元素总是位于队首，
      所以出队时，并不是完全一样的遵循先进先出的原则来进行的，而是将队列中最大的元素出队。
      这点有点儿类似于给队列里元素先进行一个排序，再按照顺序出队。元素的比较规则默认按照元素值由大到小排序，
      我们可以重载  "<" 操作符来重新定义比较规则。
*/
/*
priority_queue<int, vector<int>, less<int> >s;//最后的两个 > 之间有空格  //大根堆
priority_queue<int, vector<int>, greater<int> >s;              //小根堆
priority_queue优先队列
1、q.empty( )  判断一个队列是否为空

2、q.pop( )  删除队顶元素

3、q.push( )  加入一个元素

4、q.size( )  返回优先队列中拥有的元素个数

5、q.top( )  返回优先队列的队顶元素
priority_queue <int, vector<int>, greater<int> > q; //小根堆
priority_queue <int, vector<int>, less<int> > q;   //大根堆

多出了两个参数，vector<>和less<>(greater<>)。
第二个参数vector<>是用来承载底层数据结构堆（heap）的容器；
第三个参数less<>或者greater<>是对第一个参数的比较类，less<int>表示数字越大优先级越大，greater<int>表示数字越小,优先级越大
————————————————
版权声明：本文为CSDN博主「李歘歘」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_42410605/article/details/100537452


https://blog.csdn.net/weixin_36888577/article/details/79937886
*/
int main()
{
    priority_queue<int>q;//声明一个优先队列q，元素值越大优先级越高
    q.push(8);
    q.push(5);
    q.push(6);
    q.push(4);
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    priority_queue <int, vector<int>, greater<int> > q1; //从小到大的优先队列
    q1.push(8);
    q1.push(5);
    q1.push(6);
    q1.push(4);
    while(!q1.empty()){
        cout<<q1.top()<<" ";
        q1.pop();
    }
    cout<<endl;
    return 0;
}
