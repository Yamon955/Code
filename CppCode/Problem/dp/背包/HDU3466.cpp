//先买q大而p小的比较好，所以按照q-p排序，注意是从小到大排序，因为背包公式中
//f[i]=max(f[i],f[i-m]+v)是假设i-m被装满时再装下一件，是假设倒着装的。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[5005];
int n,m;
struct proud
{
    int p,q,v,ch;
};
bool cmp(proud a,proud b)
{
    return a.ch<b.ch;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(f,0,sizeof(f));
        proud pr[505];
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&pr[i].p,&pr[i].q,&pr[i].v);
            pr[i].ch=pr[i].q-pr[i].p;
        }
        sort(pr+1,pr+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=pr[i].q;j--)
            {
                f[j]=max(f[j],f[j-pr[i].p]+pr[i].v);
            }
        }
        int ans=0;
        printf("%d\n",f[m]);
    }
    return 0;
}