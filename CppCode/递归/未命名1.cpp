#include <iostream>
#include <math.h>

using namespace std;
/*
测试数据：
 
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
        // 排除n=1,2的情况
        cout << n << " " << n;
    }else{
        
        // 互不相同自然数之和
        long long _res1 = 1;
        if (n == 3 || n == 4) {
            // 排除n=3,4的情况
            _res1 = n - 1;
        }else{
            
            int _count = 0;
            int _rest = 0,_avg = 0,_mod = 0;
            int a[n + 1];// a[0] 和 a[1]未使用
            
            for(int i = 2; i <= n; i++){
                // 初始化a
                a[i] = 1;
            }
            
            for(int i = 2; i <= n; i++)
            {
                _count += i;
                if(_count > n)
                {
                    _rest = n - (_count - i);// 多出来的部分
                    
                    if (_rest < (i - 2)) {// 不够每个已选的数都分到1
                        _avg = 1;
                        _mod = 0;
                    }else{// 每个已选的数至少能分到1
                        _avg = _rest / (i - 2);// 平均分个前i - 2个已确定的数
                        _mod = _rest % (i - 2);// 平均分后剩下的
                    }
                    
                    for(int j = i - 1; j >= i - _rest; j--){
                        // 从后往前分配多出来的部分
                        a[j] += _avg;
                    }
                    
                    a[i-1] += _mod;//最后一位+_mod
                    break;
                }
                
                a[i] = i;
            }
            
            for(int i = 2; i <= n; i++)
            {
                _res1 *= a[i];
            }
        }
        
        
        //若干自然数之和
        /*
         归纳公式如下：
         1)max{m1*m2*...*mk} = 3^(n/3)        if n(mod 3)等于0
         2)max{m1*m2*...*mk} = 4*3^[(n-4)/3]  if n(mod 3)等于1
         3)max{m1*m2*...*mk} = 2*3^[(n-2)/3]  if n(mod 3)等于2
         
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
