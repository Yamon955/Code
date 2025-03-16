#include<iostream>
#include<cstdio>
using namespace std;
//w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1) % 7;
int Day(int y,int m,int d)
{
    if(m==1){
            y=y-1;
            m=13;
        }
        else if(m==2){
            y=y-1;
            m=14;
        }
    int w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1) % 7;
    return w;
}
int is_run(int y)
{
    if(y%400==0 || (y%4==0&&y%100!=0)) return true;
    return false;
}
int main()
{
   int n;
   cin>>n;
   while(n--){
       int y,m,d;
        scanf("%d-%d-%d", &y, &m, &d);//日期还能这样输入
       int w = Day(y,m,d);
       int i;
       for(i=y+1;;i++){
           if(m==2&&d==29){
               if(is_run(i)&&Day(i,m,d)==w) break;
           }
           else if(Day(i,m,d)==w) break;
       }
       cout<<i<<endl;
   }
    return 0;
}
// int main()
// {
//    int n;
//    cin>>n;
//    while(n--){
//        string s;
//        cin>>s;
//        int flag=0;
//        int cnt=0;
//        char s1[10],s2[10],s3[10];
//        for(int i=0;i<s.length();i++){
//            if(s[i]=='-'){
//                flag++;
//                cnt=0;
//            }
//            else if(flag==0){
//                s1[cnt++]=s[i];
//            }
//            else if(flag==1){
//                s2[cnt++]=s[i];
//            }
//            else s3[cnt++]=s[i];
//        }
//        int y = (s1[0]-'0')*1000+(s1[1]-'0')*100+(s1[2]-'0')*10+(s1[3]-'0');
//        int m = (s2[0]-'0')*10+(s2[1]-'0');
//        int d = (s3[0]-'0')*10+(s3[1]-'0');
//        //cout<<y<<" "<<m<<" "<<d<<endl;
//        int w = Day(y,m,d);
//        int i;
//        for(i=y+1;;i++){
//            if(m==2&&d==29){
//                if(is_run(i)&&Day(i,m,d)==w) break;
//            }
//            else if(Day(i,m,d)==w) break;
//        }
//        cout<<i<<endl;
//    }
//     return 0;
// }