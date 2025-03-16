#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Point{
    float x,y;
};
float x,y,x2,y2;
void get_point(Point p[],int i)
{
    p[i].x=p[i+1].x=min(x,x2);
    p[i+2].x=p[i+3].x=max(x,x2);
    p[i].y=p[i+2].y=min(y,y2);
    p[i+1].y=p[i+3].y=max(y,y2);
}
int main()
{
    Point p[8];
    cin>>x>>y>>x2>>y2;
    get_point(p,0);
    cin>>x>>y>>x2>>y2;
    get_point(p,4);
    float xlen,ylen;
    if(p[0].x<=p[4].x){
        xlen=p[3].x-p[0].x-(p[4].x-p[0].x);
    }
    else{
        xlen=p[7].x-p[4].x-(p[0].x-p[4].x);
    }
    if(p[3].y<=p[7].y){
        ylen=p[3].y-p[2].y-(p[4].y-p[0].y);
    }
    else {
        ylen=p[7].y-p[6].y-(p[0].y-p[4].y);
    }
    if(xlen<0 || ylen<0) cout<<"0.00"<<endl;
    else printf("%.2f\n",xlen*ylen);
    return 0;


}