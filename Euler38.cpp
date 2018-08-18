/*************************************************************************
	> File Name: Euler38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时39分41秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int is_valid(int a){
    int num[10] = {0};
    int n = 0, digit = 0, ans;
    do{
        n += 1;
        ans =  a * n;
        while(ans){
            if(ans % 10 == 0) return 0;
            if(num[ans % 10]) return 0;
            num[ans % 10] = 1;
            ans /= 10;
            digit += 1;
        }
    }while(digit < 9);
    if(digit > 9) return 0;
    int ret = 0;
    for(int i = 1; i <= n; i++){
        int y = a * i;
        //用于将各乘积拼接再一起
        ret = ret * (int)pow(10, floor(log10(y)) + 1) + y;
    }
    return ret;
}

int main(){
    int temp = 0, ans = 0;
    for(int i = 1; i < 10000; i++){
        temp = is_valid(i);
        if(ans < temp) ans = temp;
    }
    printf("%d\n", ans);
    return 0;
}
