#include <iostream>
#include <math.h>

using namespace std;
/*
�������ݣ�
 
1
 
2
 
3
 
4
 
10
 
30
 
*/
int main()
{
    int n;
    cin >> n;
    

    if(n == 1 || n == 2)
    {
        // �ų�n=1,2�����
        cout << n << " " << n;
    }else{
        
        // ������ͬ��Ȼ��֮��
        long long _res1 = 1;
        if (n == 3 || n == 4) {
            // �ų�n=3,4�����
            _res1 = n - 1;
        }else{
            
            int _count = 0;
            int _rest = 0,_avg = 0,_mod = 0;
            int a[n + 1];// a[0] �� a[1]δʹ��
            
            for(int i = 2; i <= n; i++){
                // ��ʼ��a
                a[i] = 1;
            }
            
            for(int i = 2; i <= n; i++)
            {
                _count += i;
                if(_count > n)
                {
                    _rest = n - (_count - i);// ������Ĳ���
                    
                    if (_rest < (i - 2)) {// ����ÿ����ѡ�������ֵ�1
                        _avg = 1;
                        _mod = 0;
                    }else{// ÿ����ѡ���������ֵܷ�1
                        _avg = _rest / (i - 2);// ƽ���ָ�ǰi - 2����ȷ������
                        _mod = _rest % (i - 2);// ƽ���ֺ�ʣ�µ�
                    }
                    
                    for(int j = i - 1; j >= i - _rest; j--){
                        // �Ӻ���ǰ���������Ĳ���
                        a[j] += _avg;
                    }
                    
                    a[i-1] += _mod;//���һλ+_mod
                    break;
                }
                
                a[i] = i;
            }
            
            for(int i = 2; i <= n; i++)
            {
                _res1 *= a[i];
            }
        }
        
        
        //������Ȼ��֮��
        /*
         ���ɹ�ʽ���£�
         1)max{m1*m2*...*mk} = 3^(n/3)        if n(mod 3)����0
         2)max{m1*m2*...*mk} = 4*3^[(n-4)/3]  if n(mod 3)����1
         3)max{m1*m2*...*mk} = 2*3^[(n-2)/3]  if n(mod 3)����2
         
         */
        
        long long _res2 = 1;
        
        if(n % 3 == 0){
            
            _res2 = pow(3,n/3);
        }else if(n % 3 == 1){
            
            _res2 = 4*pow(3,(n-4)/3);
        }else{
            
            _res2 = 2*pow(3,(n-2)/3);
        }
        cout << _res1 << " " << _res2;
    }
    
    cout << endl;
    return 0;
}
