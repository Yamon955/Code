/*
����һ��n*n�����̣�����Ҫ�������з���n���ڻʺ��n���׻ʺ�ʹ����������ڻʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϣ�����������׻ʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϡ����ܹ��ж����ַŷ���nС�ڵ���8��
*/
#include<iostream>
#include<cstring>
using namespace std;
int b[1000],c[1000],d[1000];
int e[1000],f[1000],g[1000];
int map[10][10];
int total=0;
int n;
void queen2(int x)
{
	if(x>n){
		total++;
		return ;
	}
	for(int j=1;j<=n;j++){
		if(e[j]==0 && f[x+j]==0 && g[x-j+n]==0 && map[x][j]==0){
			e[j]=1;
			f[x+j]=1;
			g[x-j+n]=1;
			map[x][j]=1;
			queen2(x+1);
			e[j]=0;
			f[x+j]=0;
			g[x-j+n]=0;
			map[x][j]=0;
		}
	}
	
}
void queen1(int x)
{
	if(x>n) {
		queen2(1);//�Ƚ�n���׻ʷźú���ٷźڻʺ������������������ڰ׻ʺ����ڵĿպڻʺ��ܷ� 
		return;
	}
	for(int j=1;j<=n;j++){
		if(b[j]==0 && c[x+j]==0 && d[x-j+n]==0){
			b[j]=1;
			c[x+j]=1;
			d[x-j+n]=1;
			map[x][j]=1;
			queen1(x+1);
			b[j]=0;
			c[x+j]=0;
			d[x-j+n]=0;
			map[x][j]=0;
		}
	}
 } 
int main()
{
	int T;
	cin>>T;
	while(T--){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) map[i][j]=0; 
		cin>>n;
		total=0;
		queen1(1);
		cout<<total<<endl;
	}
	
	return 0;
 } 
