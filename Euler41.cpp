/*************************************************************************
	> File Name: Euler41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 09时08分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_N 1000000000

int prime[MAX_N + 5] = {0};

void init(){
    for(int i = 2; i < MAX_N; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] >= MAX_N) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}


int is_need(int a){
    int num[10] = {1}, times = floor(log10(a)) + 1;
    while(a){
        if(num[a % 10]) return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    for(int i = 1; i <= times; i++){
        if(num[i] == 0) return 0;
    }
    return 1;
}

int main(){
    init();
    int ans = 0;
    for(int i = 1; i <= prime[0]; i++){
        if(is_need(prime[i]) && ans < prime[i]){
            ans = prime[i];
        }
    }
    printf("%d\n", ans);

    return 0;
}
