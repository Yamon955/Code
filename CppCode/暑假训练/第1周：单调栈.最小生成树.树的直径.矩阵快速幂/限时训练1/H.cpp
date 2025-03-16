#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
char s[100005],ans[40];
int a[100005],num[40],vis[40];
int main()
{
    cin>>s;
    int len = strlen(s);
    for(int i=0;i<len;i++) num[s[i]-'a']++;
    int cnt = 0;
    for(int i=0;i<len;i++){
        if(ans[cnt-1]==s[i]){
            num[s[i]-'a']--;
            continue;
        }
        num[s[i]-'a']--;
        while(cnt>0 && !vis[s[i]-'a'] && ans[cnt-1]>s[i] && num[ans[cnt-1]-'a']>0){
            vis[ans[cnt-1]-'a'] = 0;
            cnt --;
        }
        if(vis[s[i]-'a']==0){
            ans[cnt++] = s[i];
            vis[s[i]-'a'] = 1;
        }

    }
    for(int i=0;i<cnt;i++) cout<<ans[i];
    return 0;
}