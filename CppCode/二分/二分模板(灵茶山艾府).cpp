#include<iostream>
using namespace std;

int num[10000];
//https://leetcode.cn/link/?target=https%3A%2F%2Fb23.tv%2FCBJnyNJ
//尽量看自己写的二分模板
int lower_bound(int target)
{
    int left = 0;
    int right = num.size() - 1;  // 闭区间  [left , right]
    while(left <= right){  //区间不空---> left > right 时区间为空
        //int mid = left + (right - left) >> 1 ;  可以避免溢出
        int mid = (left + right) >> 1;  
        if(num[mid] < target)   // [mid+1 , right]
            left = mid + 1;
        else                   //[left , mid]
            right = mid;
    }
    return left;  //left = right + 1
}
int lower_bound_2(int target)
{
    int left = 0;
    int right = num.size();  // 左闭右开区间  [left , right)
    while(left < right){  //区间不空 left == right 时区间为空
        //int mid = left + (right - left) >> 1 ;  可以避免溢出
        int mid = (left + right) >> 1;  
        if(num[mid] < target)   // [mid+1 , right)
            left = mid + 1;
        else                   //[left , mid）
            right = mid;
    }
    return left; //left == right

}
int lower_bound_3(int target)
{
    int left = -1;
    int right = num.size();  // 开区间  (left , right)
    while(left + 1 < right){  //区间不空 left + 1 == right 时区间为空
        //int mid = left + (right - left) >> 1 ;  可以避免溢出
        int mid = (left + right) >> 1;  
        if(num[mid] < target)   // (mid , right)
            left = mid;
        else                   //(left , mid）
            right = mid;
    }
    return left + 1; //left + 1 == right
}