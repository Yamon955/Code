#include<iostream>
#include<cstdio>
using namespace std;
int p[30010],Size[30010];
int find(int a)
{
    if(p[a]!=a) p[a]=find(p[a]);
    return p[a];
}
int main()
{
    int P;
    cin>>P;
    for(int i=1;i<=P;i++){
        p[i]=i;
        Size[i]=0;
    }
    while(P--){
        char ch;
        cin>>ch;
        if(ch=='M'){
            int a,b;
            cin>>a>>b;
            if(find(a)!=find(b)){
                if(p[b]==b) Size[find(a)]+=1;
                else Size[find(a)]+=Size[find(b)];
                p[find(b)]=find(a);
            }
        }
        else {
            int a;
            cin>>a;
            cout<<Size[find(a)]<<"¸ö"<<endl;
        }
    }   
    return 0;
}