//AC wing--845
#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<queue>
#include<cstring>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
queue<string>r;
unordered_map<string,int>p;//寻找p[string]值时--->O(1)
//引用map函数的作用记录得到该字符串所需要的步数
//map<string,int>  寻找p[string]值时--->O(logn)--->map自动排序，故时间复杂度高一些
string st;
int main()
{
    char ch;
    for(int i=0;i<9;i++){
        cin>>ch;
        st+=ch;
    }
    r.push(st);//入队
    p[st]=0;//开始的字符串得到步数初始化为0
    while(!r.empty()){
        string tmp=r.front();
        int id=p[tmp];//后面tmp可能改变，故先把当前得到对头所需要的步数存起来备用
        if(tmp=="12345678x"){ //找到目标字符串，返回所需步数-->bfs先搜到的即为最少步数
            cout<<id<<endl;
            return 0;//结束程序
        }
        int x,y;
        for(int i=0;i<9;i++){
            if(tmp[i]=='x'){
                x=i/3;//将一维数组下标转化为二维坐标，从(0,0)->(2,2)
                y=i%3;
                break;
            }
        }
        for(int j=0;j<4;j++){
            int nx=x+dx[j],ny=y+dy[j];//向四周搜
            if(nx<0||ny<0||nx>2||ny>2) continue;
            swap(tmp[x*3+y],tmp[nx*3+ny]);//交换两字符位置
            if(p.count(tmp)!=0){ //如果交换后得到的新字符串原来得到过
                   //map中的count函数如 r.count(s)-->如果s在map中没有出现过会返回0，否则，会返回s在map中的位序
                swap(tmp[x*3+y],tmp[nx*3+ny]);//再次改变回来，以便于向下一个方向搜的时候队头字符串不变
                continue;
            }
            //否则，如果交换后得到的新字符串原来没有得到过
            r.push(tmp);//将该新的字符串入队
            p[tmp]=id+1;//得到该字符串的步数等于当前得到队头字符串的步数(即p[r.front()]) 加 1
            swap(tmp[x*3+y],tmp[nx*3+ny]);//再次改变回来，以便于向下一个方向搜的时候队头字符串不变
        }
        r.pop();//队头出队
    }
    cout<<"-1"<<endl;
    return 0;
}
/*
在一个 3×3 的网格中，1∼8 这 8 个数字和一个 x 恰好不重不漏地分布在这 3×3 的网格中。

例如：

1 2 3
x 4 6
7 5 8
在游戏过程中，可以把 x 与其上、下、左、右四个方向之一的数字交换（如果存在）。

我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：

1 2 3
4 5 6
7 8 x
例如，示例中图形就可以通过让 x 先后与右、下、右三个方向的数字交换成功得到正确排列。

交换过程如下：

1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x
现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

输入格式
输入占一行，将 3×3 的初始网格描绘出来。

例如，如果初始网格如下所示：

1 2 3 
x 4 6 
7 5 8 
则输入为：1 2 3 x 4 6 7 5 8

输出格式
输出占一行，包含一个整数，表示最少交换次数。

如果不存在解决方案，则输出 −1。

输入样例：
2  3  4  1  5  x  7  6  8
输出样例
19
*/