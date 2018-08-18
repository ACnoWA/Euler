/*************************************************************************
	> File Name: Euler36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 14时11分02秒
 ************************************************************************/
//进制转换：将一个十进制转换为m进制，可知十进制可表示为m进制的an*m^n+an-1*m^n-1+an-2*m^n-2+……+a1*m+a0;由于除去a0项以外，剩余的所有项均为m的倍数，所以对原数模m所得结果定为a0,再对原数除m则之前的an到a1所对应的所有的次幂降一（可将累加式提出一个m就可以看出）则对a1的求法就与a0一致，之后的项都是同理。
#include <stdio.h>
#include <math.h>
//该函数是完成n进制下的整数翻转
int is_palindromic(int x, int n){
   int temp = x, num = 0;
    while(x){
        num = num * n +  x % n;
        x /= n;
    }
    
    return temp == num;
}
int main(){
    
    int ans  = 0;
    for(int i = 1; i < 1000000; i++){
        if(!is_palindromic(i, 2)) continue;
        if(!is_palindromic(i, 10)) continue;
        ans += i;
    }
    printf("%d\n",ans);
    return 0;
}

