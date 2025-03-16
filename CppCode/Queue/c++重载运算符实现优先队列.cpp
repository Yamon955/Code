#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
class HeapNode{
    private:
        char data;
        int length;
    public:
        HeapNode(){}
        HeapNode(char a,int b){data = a,length = b;}
        bool operator < (const HeapNode& node)const{
             return length < node.length; //从大到小，length数值越大优先级越高
            //return length > node.length;   //从小到大，length数值越小优先级越高
        }
        void print(){cout<<data<<" "<<length<<endl;}
};
priority_queue<HeapNode> q;

int main()
{
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        char ch;
        int a;
        cin>>ch>>a;
        q.push(HeapNode(ch,a));
    }
    while(!q.empty()){
        HeapNode tmp = q.top();
        tmp.print();
        q.pop();
    }
    return 0;
}
/*
5
a 1
b 5
c 3
d 2
e 4
*/

