#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double _min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
double _max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
double x,y,x2,y2,x3,y3,x4,y4;
int main()
{
    int T;
    cin>>T;
    while(T--){
    	cin>>x>>y>>x2>>y2>>x3>>y3>>x4>>y4;//输出每个矩阵对角线上两点的坐标
		double a,b,c,d,e,f,g,h;
		a=_min(x,x2);  //将每个矩阵的对角线转化成 左下到右上的形式
		b=_min(y,y2);
		c=_max(x,x2);
		d=_max(y,y2);
		e=_min(x3,x4);
		f=_min(y3,y4);
		g=_max(x3,x4);
		h=_max(y3,y4);
		if(a>=g||b>=h||e>=c||f>=d) cout<<"0.00"<<endl;
		else {
			printf("%0.2lf\n",(_min(c,g)-_max(a,e))*(_min(d,h)-_max(b,f)));
		}
	}
    return 0;


}