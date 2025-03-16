#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

char s[1005],p[1005];
int ans = 0;
int main()
{
    cin>>s;
    cin>>p;
    for(int i=0;i<strlen(s);i++){
        if(s[i] != p[i]){
            s[i] = p[i];
            if(s[i+1] == 'o') s[i+1] = '*';
            else s[i+1] = 'o';
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}