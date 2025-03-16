#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char x[100],y[100];//�����ַ���
int m[100][100];//m[i][j]��ʾ x[0]~x[i] �� y[0]~y[j] ������������еĳ���
int v[100][100];//��¼m[i][j]���Ǹ�ʽ�������ģ�������������������
/*
˼�룺
������X={x1,x2,��,xm}��Y={y1,y2,��,yn}�������������ΪZ={z1,z2,��,zk} ����
(1)��xm=yn,��zk=xm=yn����Zk-1��Xm-1��Yn-1������������С�
(2)��xm��yn��zk��xm����Z��xm-1��Y������������С�
(3)��xm��yn��zk��yn����Z��X��yn-1������������С�
���У� Xm-1={x1,x2,��,xm-1}��Yn-1={y1,y2,��,yn-1} ��Zk-1={z1,z2,��,zk-1} 
*/
/*
     dp��ʼ������ m[0][i]=m[i][0]=0                 i<=n;
     dp����   ��m[i][j]=m[i-1][j-1]+1               x[i]==y[j]
                m[i][j]=max(m[i-1][j],m[i][j-1])   x[i]!=y[j]
*/
void LCSLength(int l,int r)//��̬�滮��
{
    for(int i=1;i<=l;i++) m[i][0]=0;
    for(int i=1;i<=r;i++) m[0][i]=0;
    for(int i=1;i<=l;i++)
        for(int j=1;j<=r;j++){
            if(x[i]==y[j]){
                m[i][j]=m[i-1][j-1]+1;
                v[i][j]=1;
            } 
            else if(m[i-1][j]>=m[i][j-1]) {
                m[i][j]=m[i-1][j];
                v[i][j]=2;
            }
            else  {
                m[i][j]=m[i][j-1];
                v[i][j]=3;
            }
        }
}
void LCS(int i,int j)//�������� v[][] ��������������
{
    if(i == 0 || j == 0) return;
    if(v[i][j] == 1){
        LCS(i-1,j-1);
        cout<<x[i];
    }
    else if(v[i][j] == 2) LCS(i-1,j);
    else   LCS(i,j-1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int _max(int x,int y)
{
    return x>y?x:y;
}
int RecurLCSLength(int l,int r)//�ݹ�
{
    if(l==0 || r==0) return 0;
    if(x[l]==y[r]) return RecurLCSLength(l-1,r-1)+1;
    else return _max(RecurLCSLength(l-1,r),RecurLCSLength(l,r-1));
}
int main()
{
    cin>>x>>y;//�涨�ַ�����0λΪ�����ַ�����������󹫹������й���
    int xlen=strlen(x)-1;
    int ylen=strlen(y)-1;
    cout<<"�ݹ����������������еĳ���:"<<RecurLCSLength(xlen,ylen)<<endl;//����ݹ����������������еĳ���
    LCSLength(xlen,ylen);
    cout<<"dp���������������еĳ���:"<<m[xlen][ylen]<<endl;
    cout<<"dp����������������Ϊ:";
    LCS(xlen,ylen);
    cout<<endl;
    cout<<"����m:"<<endl;
    for(int i=0;i<=xlen;i++){
        for(int j=0;j<=ylen;j++) cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<"����v:"<<endl;
    for(int i=0;i<=xlen;i++){
        for(int j=0;j<=ylen;j++) cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/*
���룺 
*abcbdab
*bdcaba
*/