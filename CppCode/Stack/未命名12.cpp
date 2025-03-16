#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
stack<double> num_stack;
stack<char> op_stack;
int is_operator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(' || ch==')' || ch=='=') return 1;
    else return 0;
}
int judge_operate(char a,char b){
    if(a=='+' || a=='-' || a=='='){
        if(b=='*' || b=='/' || b=='('){
            return -1;
        }
        else return 1;
    }
    else if(a=='*' || a=='/'){
        if(b=='(') return -1;
        else return 1;
    }
    else if(a=='(') return 0;
}

int main(){
     char ch=getchar();
     while(ch!='='){
         if(!is_operator(ch)){
             double x=0,y=0;//分整数小数计算
             while(ch!='.' && '0'<=ch && ch<='9'){
                 x=x*10+ch-'0';
                 ch=getchar();
             }
             if(ch=='.') ch=getchar();
             int e=1;
             while('0'<=ch && ch<='9'){
                 y=y+(ch-'0')*pow(10,-e);
                 e++;
                 ch=getchar();
             }
            num_stack.push((x+y));
         }
         else{
            if(op_stack.empty()) { op_stack.push(ch);ch=getchar();}//空的话无条件读入
            else{
                char opa;
               opa=op_stack.top();
                if(judge_operate(opa,ch)==-1){op_stack.push(ch);ch=getchar();}//来的优先级比他高 继续进站
                else if(judge_operate(opa,ch)==1){//优先级低或相等
                    double a,b,ans=0;char e;
                   b=num_stack.top();
				   num_stack.pop();
				   a=num_stack.top();
				   num_stack.pop();
                         if(opa=='+') ans=a+b;
                    else if(opa=='-') ans=a-b;
                    else if(opa=='*') ans=a*b;
                    else if(opa=='/') ans=a/b;
                    op_stack.pop();
                    num_stack.push(ans);
					if(ch==')'){
						op_stack.pop();
						ch=getchar();
					}
					else{
						op_stack.push(ch);ch=getchar();
					}
                }
                else {op_stack.push(ch);ch=getchar();}
            }
             
             
         }
     }
     if(ch=='='){
		   double a,b,ans;
		 while(!op_stack.empty()){
         a=0,b=0,ans=0; char opa;
                   b=num_stack.top();
				   num_stack.pop();
				   a=num_stack.top();
				   num_stack.pop();
                   opa=op_stack.top();
				   op_stack.pop();
                         if(opa=='+') ans=a+b;
                    else if(opa=='-') ans=a-b;
                    else if(opa=='*') ans=a*b;
                    else if(opa=='/') ans=a/b;
                  
                  num_stack.push(ans);
     	}
		ans=num_stack.top();
		printf("%.2f",ans);
                   return 0;
	 }

}
