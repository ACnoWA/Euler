/*************************************************************************
	> File Name: Euler32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 14时25分38秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 10000

int get_digit(int a, int *num){
    while(a){
        if(a % 10 == 0) return 0;
        if(num[a % 10]) return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    return 1;
}

int is_valid(int a, int b, int c){
    int num[10] = {0};
    if(!get_digit(a, num)) return 0;
    if(!get_digit(b, num)) return 0;
    if(!get_digit(c, num)) return 0;
    return 1;
}

int digit(int a){
    return floor(log10(a)) + 1;
}

int valid[MAX_N] = {0};

int main(){
    int ans = 0;
    for(int i = 2; i < 100; i++){
        if( i < 10){
            for(int j = 1345; j < 5000; j++){
                if(digit(i) + digit(j) + digit(i * j) < 9) continue;
                if(!is_valid(i, j, i * j)) continue;
                ans += i * j * (1 - valid[i * j]);
                valid[i * j] = 1;
                printf("%d * %d = %d\n", i, j, i*j);
            }
        }

        if(i >= 10){
            for(int j = 100; j < 1000; j++){
                if(digit(i) + digit(j) + digit(i * j) < 9) continue;
                if(!is_valid(i, j, i * j)) continue;
                ans += i * j *(1 - valid[i * j]);
                valid[i * j] = 1;
                printf("%d * %d = %d\n", i, j, i * j);
            }    
        }
    }

    printf("%d\n", ans);
    return 0;
}
