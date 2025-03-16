#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int f[25][25];
int x[20],y[20];
int best=1e9;//最优人数
int best_x[20],best_y[20];//存储最优解
bool judge()//判断是否全部看守
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j]==0) return false;
    return true;
}
void traceBack(int k)
{
    if(judge()){
        if(k < best){
        	best = k;
        	for(int i=0;i<best;i++){
            	best_x[i]=x[i];
            	best_y[i]=y[i];
        	}
		}
        return;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int flag=0;
            if(f[i][j]==0){//当前(i,j)无人看守
                for(int w=0;w<4;w++){
                    int nx=i+dx[w],ny=j+dy[w];
                    if(nx<=0||ny<=0||nx>m||ny>m) continue;
                    if(f[nx][ny]==1) {
                        flag=1;//判断标志,看(i,j)四周是否有人
                        break;
                    }
                }
                if(flag==1) break;//当前(i,j)四周中有人人看守不可以设置一个哨位，循环下一个位置
                f[i][j]=1;//当前(i,j)四周都无人看守可以设置一个哨位
                for(int w=0;w<4;w++){
                    int nx=i+dx[w],ny=j+dy[w];
                    if(nx<=0||ny<=0||nx>m||ny>m) continue;
                    f[nx][ny]=1;//四周置为有人看守
                }
                x[k]=i;
                y[k]=j;
                if(k<best) traceBack(k+1);//去找下一个哨位的地方
                f[i][j]=0;
                for(int w=0;w<4;w++){
                    int nx=i+dx[w],ny=j+dy[w];
                    if(nx<=0||ny<=0||nx>m||ny>m) continue;
                    f[nx][ny]=0;//回溯
                }
            }
            
        }
    }
}
int main()
{
    cin>>m>>n;
    traceBack(0);
    if(best==1e9){
        cout<<"No Solution!";
        return 0;
    }
    cout<<best<<endl;
    for(int i=0;i<best;i++){
    	//cout<<x[i]<<" "<<y[i]<<endl;
    	f[best_x[i]][best_y[i]]=2;
	}
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		if(f[i][j]==2) cout<<'1';
    		else cout<<'0';
		}
		cout<<endl;
	}
    return 0;
}
/*
cin>>4 4
4   
0100
0001
1000
0010
*/