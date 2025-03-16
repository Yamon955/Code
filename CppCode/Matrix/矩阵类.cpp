#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
class Matrix{
    private:
        int row,col;
        double *data;
    public:
    Matrix();
    Matrix(int r,int c,double *data);
    Matrix(const Matrix& M);
    ~Matrix();
    void ShowMatrix();
    void MatrixAdd(Matrix a,Matrix b);
    void MatrixSub(Matrix a,Matrix b);
    void MatrixMul(Matrix a,Matrix b);
    double MatrixFrobenius();
    void MatrixFollow(Matrix a);
    void MatrixInverse(Matrix a,double Frobenius);

};
Matrix::Matrix(){
    row=0;
    col=0;
    data=NULL;
}
Matrix::Matrix(int r,int c,double *item):row(r),col(c){
    data= new double[r*c];
    for(int i=0;i<r*c;i++) data[i]=item[i];
}
Matrix::Matrix(const Matrix &M){
    row=M.row;
    col=M.col;
    data=new double[row*col];
       for(int i=0;i<row*col;i++) data[i]=M.data[i];

}
Matrix::~Matrix(){
    if(data!=NULL){
    delete[] data;
    data=NULL;
    }
}
void Matrix::MatrixAdd(Matrix a,Matrix b){
    int r1=a.row,r2=b.row;
    int c1=b.col,c2=b.col;
    if(r1!=r2 || c1!=c2){
        printf("Can't add those two Matrix\n");
        return ;
    }
    row=r1;col=c1;
    data=new double[row*col];
    for(int i=0;i<=r1*c1;i++) data[i]=a.data[i]+b.data[i];
}
void Matrix::MatrixSub(Matrix a,Matrix b){
    int r1=a.row,r2=b.row;
    int c1=b.col,c2=b.col;
    if(r1!=r2 || c1!=c2){
        printf("Can't sub those two Matrix\n");
        return ;
    }
    row=r1;col=c1;
    data=new double[row*col];
    for(int i=0;i<r1*c1;i++) data[i]=a.data[i]-b.data[i];
}
void Matrix::MatrixMul(Matrix a,Matrix b){
    int r1=a.row,r2=b.row;
    int c1=b.col,c2=b.col;
    if(c1 != r2){
        cout<<"Can't mul those two Matrix"<<endl;
        return ;
    }
    row=r1;col=c2;
    int up=0;
    data=new double[row*col];
    for(int i=0;i<row*col;i++) data[i]=0;
    int k=0,cnt=0,tmp=0;
        for(int i=0;i<row;i++){
            while(k<c2){
                for(int j=i*c1;j<(i+1)*c1;j++){
                    data[cnt]+=a.data[j]*b.data[tmp];
                    tmp+=c2;
                }
                k++;
                tmp=k;
                cnt++;
            }
            tmp=0;
            k=0;
            
        }
        return ;
}
double Matrix::MatrixFrobenius(){
    int r=row,c=col;
    int sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum+=data[i*c+j]*data[i*c+j];
        }
    }
    return sqrt(sum);
}
void Matrix::MatrixFollow(Matrix a){
int r=a.row,c=a.col;
row=r,col=c;
int *temp=new int[r*c];
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        for(int k=0;k<r*c;k++) temp[k]=a.data[k];
        for(int x=i*c;x<(i+1)*c;x++) temp[x]=0;
        for(int y=j;y<r*c;y+=c) temp[y]=0;
    }
}
int sum;
for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum+=temp[i*c+j]*temp[i*c+j];
            data[i*c+j]=sqrt(sum);
        }
    }
  
}
void Matrix::MatrixInverse(Matrix a,double Frobenius){
    row=a.row;col=a.col;
    data=new double[row*col];
    for(int i=0;i<row*col;i++){
        data[i]=a.data[i]/Frobenius;
    }
return ;
}
void Matrix::ShowMatrix(){
    printf("the Matrix is:\n");
     int r=row;int c=col;
    int cnt=0;
    for(int i=0;i<r*c;i++){
        printf("%f ",data[i]);cnt++;
        if(cnt==c){
            puts("");
            cnt=0;
        }

    }
}

int main(){
   int r,c;
   printf("Enter the first Matrix,Please enter the row and col:\n");
   cin>>r>>c;
   double *temp=new double[r*c];
   cout<<"Enter elems one by one"<<endl;
   for(int i=0;i<r*c;i++) cin>>temp[i];
   Matrix M1(r,c,temp);
   delete[] temp;
    temp=NULL;
   printf("Enter the second Matrix,Please enter the row and col:\n");
   cin>>r>>c;
   temp=new double[r*c];
   cout<<"Enter elems one by one"<<endl;
   for(int i=0;i<r*c;i++) cin>>temp[i];
   Matrix M2(r,c,temp);
   delete[] temp;
   
   
}
