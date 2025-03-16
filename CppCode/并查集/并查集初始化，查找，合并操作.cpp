#include<iostream>
using namespace std;
const int MAXN=100;
int fa[MAXN];//fa[i]=j��ʾi�ĸ��ڵ�λj 
void init(int n)//��ʼ�� 
{
	for(int i=1;i<=n;i++){
		fa[i]=i;//i�ĸ��ڵ�ָ�������� 
	}
}
int find(int i)//���� 
{
	if(fa[i]==i) return i;//�ݹ���ڣ�������������λ�ã��ͷ������� 
	else return find(fa[i]);//�������ϲ������� 
}
int find_pro(int i)//����     �����ͻ�ʹͬһ�����ȵĽ�㶼ָ��������Ƚ�� 1->5,2->5,3->5,4->5,��fa[1]=fa[2]=fa[3]=fa[4]=5 
{
	if(fa[i]==i) return i;
	else {
		fa[i]=find_pro(fa[i]);//�ò�������·��ѹ����fa[i]=j,j��i����Զ�����Ƚ�� 
		return fa[i];//���ظ��ڵ� 
	}
 }
void unionn(int i,int j)//�ϲ� ---------->����һ���ܳ��ĵ��� 1->2->3->4->5 ��fa[1]=2,fa[2]=3,fa[3]=4,fa[4]=5 
{
	int i_fa=find(i);//�ҵ�i������ 
	int j_fa=find(j);//�ҵ�j������ 
	fa[i_fa]=j_fa;//i������ָ��j������ 
 } 
 
int main()
{
	int n;
	cin>>n;//5
	init(n);
	unionn(1,2);
	unionn(2,3);
	unionn(3,4);
	unionn(4,5);
	for(int i=1;i<=n;i++) cout<<fa[i]<<endl;
	cout<<endl;
	find_pro(1);
	for(int i=1;i<=n;i++) cout<<fa[i]<<endl;
	return 0;
}

