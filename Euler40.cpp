/*************************************************************************
	> File Name: Euler40.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 09时36分18秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main(){
    int temp, num[10] = {0};
   for(int i = 1; i < 8; i++){
        if(i == 1)
        num[i] = 1;
        else{
            temp = pow(10, i - 1);
            num[i] = (temp - temp / 10) * floor(log10(temp)) + num[i - 1];
        }
    }
    
    int sum = 1, j = 2, a, y, b;
    for(int i = 100; i <= 1000000; i *= 10){
        a = (i - num[j]) / j + i / 10;
        y = (i - num[j]) % j;
        if(y == 0) {
            b = a / (i / 10);
        }else{
            for(int k = 0; k < j - y; k++){
            b = a % 10;
            y = a / 10;
            }
        }
        sum *= b;
        printf("%d\n", sum);
        j++;
    }
    return 0;
}
