#include<iostream>
using namespace std;
class Matrix{
	int row,col;
	int f[100][100];
	public:
		Matrix(){}
		Matrix(int r,int c){
			row=r;col=c;
		}
		Matrix operator+(Matrix a){
			Matrix b;
			b.row=row;b.col=col;
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++) b.f[i][j]=f[i][j]+a.f[i][j];
			return b;
		}
		Matrix operator-(Matrix a){
			Matrix b;
			b.row=row;b.col=col;
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++) b.f[i][j]=f[i][j]-a.f[i][j];
			return b;
		}
		Matrix operator*(Matrix a){
			Matrix b;
			b.row=row;b.col=a.col;
			for(int i=0;i<b.row;i++)
				for(int j=0;j<b.col;j++)
					for(int c=0;c<col;c++)
						b.f[i][j]+=f[i][c]*a.f[c][j];
			return b; 
		}
		Matrix transposition(){  //求转置矩阵 
			Matrix a;
			a.row=col;a.col=row;
			for(int i=0;i<a.row;i++)
				for(int j=0;j<a.col;j++)
					a.f[i][j]=f[j][i];
			return a;
		}
		int module(){    //求矩阵的模 
		}
		friend istream& operator>>(istream &in,Matrix &a){
			for(int i=0;i<a.row;i++)
				for(int j=0;j<a.col;j++) in>>a.f[i][j];
			return in;
		}
		friend ostream& operator<<(ostream &out,Matrix &a){
			for(int i=0;i<a.row;i++){
				for(int j=0;j<a.col;j++) out<<a.f[i][j]<<" ";
				out<<endl;
			}
			return out;
		}
}; 
int main()
{
	Matrix a(2,3),b(2,2);
	cin>>a;
	cin>>b;
	Matrix c=a.transposition();
	cout<<c;
	return 0;
 } 
