#include<iostream>
#include<cstdio>
using namespace std;
// 计算给定日期星期几好象是编程都会遇到的问题，最近论坛里也有人提到这个问题，并给出了一个公式： 
//         W=   (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)   mod   7 
//         (要求将1、2月当作上一年的13、14月来计算) 
//y,   m,   d,   w   分别表示   年   月   日   星期(w=0-6   代表星期日-星期六
int main()
{
    int y,m,d,w;
    while(1){
        cin>>y>>m>>d;
        // if(m==1){
        //     y=y-1;
        //     m=13;
        // }
        // else if(m==2){
        //     y=y-1;
        //     m=14;
        // }
        if(m==1||m==2){
            m+=12;
            y--;
        }
        w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1) % 7;
        cout<<w<<endl;
    }
    return 0;
}