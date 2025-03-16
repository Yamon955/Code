#include<iostream>
using namespace std;
/*
�����ʽ����һ������M��NΪ������1<=N<=20000������Щ�˱��Ϊ1��2��3......������M��(1<=M<=1000000)��ÿ����������a,b����ʾa,b�����ݡ�
		�ڶ�������Q��ʼ������Q����Q��ѯ�ʣ�1<=Q<=1000000)��ÿ��c,d��ʾѯ��c,d�Ƿ�������
�����ʽ������ѯ��c,d����c,d�����ݾ����YES���������NO��
*/
int fa[20010];
void init(int n)
{
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int find(int i)
{
	if(fa[i]==i) return i;
	else {
		fa[i]=find(fa[i]);
		return fa[i];
	}
}
void unionn(int i,int j)
{
	int i_fa=find(i);
	int j_fa=find(j);
	fa[i_fa]=j_fa;
}
int main()
{
	int n,m,a,b,q,c,d;
	cin>>n>>m;
	init(n);
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		unionn(a,b); 
	}
	cin>>q;
	while(q--){
		cin>>c>>d;
		if(find(c)==find(d)){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	//for(int i=1;i<=n;i++) cout<<fa[i]<<endl;
	return 0;
 } 
/*
10 7
2 4
5 7
1 3
8 9
1 2
5 6
2 3
3
3 4
7 10
8 9
-->
YES
NO
YES
*/
/*
#include<iostream>
using namespace std;
int m,n;
int p[20010];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++) p[i]=i;
    while(m--){
        int a,b;
        cin>>a>>b;
        //if(find(a)!=find(b))
            p[find(a)]=find(b);
        
    }
    int Q;
    cin>>Q;
    while(Q--){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;

}
*/
