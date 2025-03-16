#include<iostream>
#include<cmath>
using namespace std;
class Matrix{
	int row,col;
	double **f;
	public:
		Matrix(){row=0;col=0;f=NULL;}
		Matrix(int r,int c);
		Matrix(const Matrix &a);//拷贝构造函数 
		~Matrix();
		Matrix operator+(Matrix a);
		Matrix operator-(Matrix a);
		Matrix operator*(Matrix a);
		Matrix& operator=(const Matrix& a);
		Matrix operator/(double b);//重载矩阵与double类型的除运算符->用于求逆矩阵A(-1)=A*/|A| 
		double moudle();//矩阵求模
		friend Matrix follow_(Matrix a);//求伴随矩阵 
		friend Matrix inverse_(Matrix a);//求逆矩阵
		friend double get_det_value(double **a,int n);//求n阶行列式的值            ->辅助求伴随矩阵 
		friend Matrix Matrix_i_j(int i,int j,Matrix b);//求矩阵b去掉i行j列后的矩阵 ->辅助求伴随矩阵 
		friend ostream& operator<<(ostream &out,Matrix &a);
		friend istream& operator>>(istream &in,Matrix &a);
}; 
Matrix::Matrix(int r,int c)
{
	row=r;col=c;
	f=new double*[row];
	for(int i=0;i<row;i++){
		f[i]=new double[col];
	}
}
Matrix::Matrix(const Matrix &a)
{
	row=a.row;col=a.col;
	f=new double*[row];
	for(int i=0;i<row;i++){
		f[i]=new double[col];
		for(int j=0;j<col;j++)
			f[i][j]=a.f[i][j];
	}
 } 
Matrix::~Matrix()
{
	for(int i=0;i<row;i++) 
		delete f[i];
	delete f;
}
Matrix Matrix::operator+(Matrix a)
{
	if(row!=a.row||col!=a.col){
		Matrix c;
		cout<<"两个矩阵维度不一致，无法相加."<<endl;
		return c;
	}
	Matrix c(row,col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			c.f[i][j]=f[i][j]+a.f[i][j];
	return c;
}
Matrix Matrix::operator-(Matrix a)
{
	if(row!=a.row||col!=a.col){
		Matrix c;
		cout<<"两个矩阵维度不一致，无法相减."<<endl;
		return c;
	}
	Matrix c(row,col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			c.f[i][j]=f[i][j]-a.f[i][j];
	return c;
}
Matrix Matrix::operator*(Matrix a)
{ 
	if(col!=a.row){
		Matrix c;
		cout<<"*左边矩阵的列数不等于右边矩阵的行数，无法相乘."<<endl;
		return c;
	}
	Matrix c(row,a.col);
	for(int i=0;i<row;i++)
		for(int j=0;j<a.col;j++)
			for(int x=0;x<col;x++)
				c.f[i][j]+=f[i][x]*a.f[x][j]; 
	return c;
}
Matrix& Matrix::operator=(const Matrix &a)
{
	if(this==&a) return *this;
	for(int i=0;i<row;i++) 
		delete f[i];
	delete f;
	row=a.row;
	col=a.col;
	f=new double*[row];
	for(int i=0;i<row;i++){
		f[i]=new double[col];
		for(int j=0;j<col;j++)
			f[i][j]=a.f[i][j];
	}
	return *this;
}
Matrix Matrix::operator/(double a)
{
	Matrix b(row,col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			b.f[i][j]=f[i][j]/a;
	return b; 
}
double Matrix::moudle()//求矩阵的模 
{
	double sum=0.0;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++){
			sum+=f[i][j]*f[i][j]; 
		} 
		
	return pow(sum,1.0/2);
}
double get_det_value(double** a,int n)//求行列式的值 
{
	if(n==1) return a[0][0];
	double res=0,t;
	double **temp;
	temp=new double*[n];
	for(int i=0;i<n;i++)
		temp[i]=new double[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-1;k++){
				if(k>=i) temp[j][k]=a[j+1][k+1];
				else     temp[j][k]=a[j+1][k]; 
			}
		t=get_det_value(temp,n-1);
		if(i%2!=0) res-=a[0][i]*t;
		else       res+=a[0][i]*t;
    }
    return res;
}
Matrix Matrix_i_j(int i,int j,Matrix a)//求矩阵a去掉i行j列后的矩阵 
{
	Matrix b(a.row-1,a.col-1);
	int r=-1,c=0;
	for(int x=0;x<a.row;x++)
		if(x!=i){
			r++;
			c=0;
			for(int y=0;y<a.col;y++){
				if(y!=j)
					b.f[r][c++]=a.f[x][y];
			}
		}
		return b; 
}
Matrix follow_(Matrix a)//求伴随矩阵 
{
	Matrix c(a.row,a.col);
	for(int i=0;i<c.row;i++)
		for(int j=0;j<c.col;j++){
			Matrix b=Matrix_i_j(j,i,a);
			double M_ij=get_det_value(b.f,b.row);
			if((i+j)%2==0) c.f[i][j]=M_ij;
			else           c.f[i][j]=-M_ij;
	}
	return c;
}
Matrix inverse_(Matrix a)//求逆矩阵
{
	Matrix c=follow_(a);
	double det=get_det_value(a.f,a.row);
	Matrix b=c/det;
	return b;
 } 
istream& operator>>(istream &in,Matrix &a)
{
	for(int i=0;i<a.row;i++)
		for(int j=0;j<a.col;j++)
			cin>>a.f[i][j];
	return in;
}
ostream& operator<<(ostream &out,Matrix &a)
{
	for(int i=0;i<a.row;i++){
		for(int j=0;j<a.col;j++){
			out<<a.f[i][j]<<" ";
		}
		out<<endl;
	}
	out<<endl;
	return out;
}
int main()
{
	Matrix a(3,3),b(3,3);
	cout<<"the 3*3 Matrix a:"<<endl;
	cin>>a;//1 2 3 1 1 1 1 3 6
	cout<<"the 3*3 Matrix b:"<<endl;
	cin>>b;//1 2 3 1 0 -1 0 1 1
	Matrix c;
	c=a+b;
	cout<<"a+b:"<<endl<<c;
	c=a-b;
	cout<<"a-b:"<<endl<<c;
	c=a*b;
	cout<<"a*b:"<<endl<<c;
	c=follow_(a);
	cout<<"a的伴随矩阵:"<<endl<<c;
	c=follow_(b);
	cout<<"b的伴随矩阵:"<<endl<<c;
	c=inverse_(a);
	cout<<"a的逆矩阵:"<<endl<<c;
	c=inverse_(b);
	cout<<"b的逆矩阵:"<<endl<<c;
	return 0;
}

