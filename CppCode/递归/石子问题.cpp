#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
///���⣺n��ʯ�ӣ�ÿ��ֻ���д���ؽ����ڵ����Ѻϳ��µ�һ�ѣ������µ�һ�ѵ�ʯ������Ϊ�ôκϲ��ĵ÷֣�
///��������պϳ�һ�ѵ���С�����÷�

int n;//����
int f[1010];//ʯ�Ӷ�
int v[1010];//������飬������Ǹ�ʯ�Ӷ���û���Ѿ����ϲ�
///////////////////////////////////////////////////////////////////////////////////////
//�����÷�˼�룺���ҳ�n��ʯ�������֮���������ڵ�����ʯ�ӣ��������Ǻϲ���һ�ѣ�
//Ȼ��ÿ�κϲ�������γɵ�ʯ�Ӷ��������������нϴ��ʯ�Ӷ�(��ÿ�κϲ����֮���������ڵ�����ʯ��)�����յó�������
int get_Max()//��������
{
    int Max=-0x3f3f3f3f;
    int Max_t;
    for(int i=0;i<n;i++)
        if(f[i]>Max){ 
            Max = f[i];  //�ҳ�����ʯ�Ӷ�
            Max_t = i;   //�������±�
        }
    int sum = Max;
    int Max_sum = 0;
    int Max_left = (Max_t-1+n) % n; //�����ʯ�Ӷѵ���������
    int Max_right = (Max_t+1) % n;
    v[Max_t] = 1;
    for(int i=0;i<n;i++){
        if(i<=n-2){
            while(v[Max_left])  Max_left = (--Max_left+n) % n;
            while(v[Max_right]) Max_right = (++Max_right) % n; 
            if(f[Max_left]>f[Max_right]) {
                sum += f[Max_left];
                Max_sum += sum;
                v[Max_left] = 1;
            }
            else {
                sum += f[Max_right];
                Max_sum += sum;
                v[Max_right] = 1;
            }
        }
        else {
            int j;
            for(j=0;j<n;j++) 
                if(!v[j]) break;
            sum += f[j];
            Max_sum += f[j]; 
        }
    }
    return Max_sum;//�������÷�
}
///����С�÷�˼�룺һ��ֻ�����n-1�Σ�ǰn-2��ֻ���������֮����С������ʯ�ӣ�
//Ȼ��ӵ��ܵ÷��в��ҽ�����һ��ʯ������Ϊ�����С�ͣ���һ�ѱ��Ϊ�ѷ���
int get_Min()
{
    memset(v,0,sizeof(v));//���������0
    int Min_sum = 0;
    for(int k=1;k<n;k++){  //һ������n-1��
        if(k<=n-2){  //ǰn-2�Σ�ÿ����������������С��ֵ
            int Min = 0x3f3f3f3f;
            int num1,num2;
            for(int i=0;i<n;i++){
                if(v[i]==0){
                    int left = (i-1+n)%n;
                    int right = (i+1)%n;
                    while(v[left])  left = (left-1+n)%n;
                    while(v[right]) right = (right+1)%n;
                    if(f[left]>f[right]){
                        if(f[i]+f[right]<Min){
                            Min = f[i]+f[right];
                            num1 = i;
                            num2 = right;
                        }
                    }
                    else {
                        if(f[i]+f[left]<Min){
                            Min = f[i]+f[left];
                            num1 = i;
                            num2 = left;
                        }
                    }
                }
            }
            f[num1] = Min;//�����֮����С��������������һ��ֵΪ��ӵĺͣ���һ����Ϊ�ѷ���
            Min_sum += Min;//�÷����
            v[num2] = 1;//���Ϊ 1
        }
        else if(k==n-1){ //���һ�Σ�ʯ�Ӷ�ֻʣ�����ѣ�ֻ�轫�����Ѽӵ��ܵĵ÷��м���
            for(int i=0;i<n;i++){
                if(v[i]==0){
                    Min_sum += f[i]; 
                }
            }
        }
        
    }
    return Min_sum;//������С�÷�
    
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    cout<<"���÷�Ϊ:"<<get_Max()<<endl;
    cout<<"��С�÷�Ϊ:"<<get_Min()<<endl;
    return 0;

}
/*
4 
4 4 5 9
*/