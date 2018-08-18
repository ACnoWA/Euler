/*************************************************************************
	> File Name: Euler35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 08时59分52秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#define RANGE 9999999
#define MAX_N 1000000

//可以直接根据该数组来判断该数是不是一个素数
int isPrime[RANGE + 5] = {0}; 
int prime[RANGE + 5] = {0};

void init(){
    for(int i = 2; i <= RANGE; i++){
        if(isPrime[i] == 0)
        prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] >= RANGE) break;
            isPrime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_need(int a){
    if(isPrime[a] != 0) return 0;
    int times = floor(log10(a)) + 1;
    int dh = pow(10, floor(log10(a)));
    for(int i = 0; i < times; i++){
        a = a / 10 + a % 10 * dh;
        if(isPrime[a] != 0) return 0;
    }
    return 1;
}

int main(){
    init();
    int sum = 0;
    for(int i = 1; i <= prime[0]; i++){
        if(prime[i] > MAX_N) break;
        if(is_need(prime[i])) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
