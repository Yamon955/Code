#include <iostream>
#include <algorithm> 
#include<cstring>
using namespace std;
//  max_step(i,j)=max(max_step(i+1,j),max_step(i+1,j+1))+step[i][j]
int n;
int step[101][101];
int _max(int a,int b)
{
    return a>b?a:b;
}
int max_step(int x,int y)///递归
{
    if(x==n-1) return step[x][y];
    else {
        return _max(max_step(x+1,y),max_step(x+1,y+1)) + step[x][y];
    }

}
int  Memory_max_step(int x,int y,int memory[][101])//记忆化递归
{
    if(memory[x][y]!=-1) return memory[x][y];
    if(x==n-1) memory[x][y]=step[x][y];
    else {
        memory[x][y]=_max(Memory_max_step(x+1,y,memory),Memory_max_step(x+1,y+1,memory))+step[x][y];
    }
    return memory[x][y];
}
int dp_max_step(int m[][101])//动态规划
{
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            m[i][j]=_max(m[i+1][j],m[i+1][j+1])+m[i][j];
        }
    }
    return m[0][0];
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
            cin>>step[i][j];
    }
    cout<<max_step(0,0)<<endl;
    int memory[101][101];
    for(int i=0;i<=n-1;i++)
        for(int j=0;j<=n-1;j++) memory[i][j]=-1;
    cout<<Memory_max_step(0,0,memory)<<endl;
    cout<<dp_max_step(step)<<endl;

    return 0;
 
}
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/