#include<iostream>
#include<cstdio>
using namespace std;
int map[1000][1000];//���� 
int sx,sy;//���ⷽ���������к� 
int tile=0,s,size; 
void ChessBoard(int tr,int tc,int sr,int sc,int s)//tr,tc��ʾ��ǰ�������ϽǷ�������кţ�s��ʾ��ǰ���̵ĳ��� 
{
	if(s==1) return;
	int t=tile++;
	s=s/2;
	//�������Ͻ����� 
	if(sr<tr+s&&sc<tc+s) ChessBoard(tr,tc,sr,sc,s);
	else {
		map[tr+s-1][tc+s-1]=t;
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	//�������Ͻ�����
	if(sr<tr+s&&sc>=tc+s) ChessBoard(tr,tc+s,sr,sc,s);
	else{
		map[tr+s-1][tc+s]=t;
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	} 
	//�������½�����
	if(sr>=tr+s&&sc<tc+s) ChessBoard(tr+s,tc,sr,sc,s);
	else {
		map[tr+s][tc+s-1]=t;
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	} 
	//�����������½�
	if(sr>=tr+s&&sc>=tc+s) ChessBoard(tr+s,tc+s,sr,sc,s);
	else{
		map[tr+s][tc+s]=t;
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
	} 
}
int main()
{
	cin>>sx>>sy>>size;
	ChessBoard(0,0,sx,sy,size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++) cout<<map[i][j]<<" ";
		cout<<endl;
	}
	cout<<tile; 
	return 0;	
}
