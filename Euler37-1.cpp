/*************************************************************************
	> File Name: Euler37-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 23时02分35秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define RANGE 50000000

int isPrime[RANGE + 5] = {0};
int prime[RANGE + 5]  = {0};

void init(){
    isPrime[0] = isPrime[1] = 1;
    for(int i = 2; i <= RANGE; i++){
        if(!isPrime[i])
        prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] >= RANGE) break;
            isPrime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

/*void init(){
    isPrime[0] = isPrime[1] = 1;
    for(int i = 2; i * i <= RANGE; i++){
        if(isPrime[i]) continue;
        for(int j = i * i; j < RANGE; j += i){
            isPrime[j] = 1;
        }
    }

    for(int i = 2; i < RANGE; i++){
        if(isPrime[i] == 0)
        prime[++prime[0]] = i;
    }
}*/

int is_need(int a){
    if(isPrime[a] != 0) return 0;
    int temp = a, dh;
    while(a){
        if(isPrime[a] != 0) return 0;
        a /= 10;
    }
    a = temp;
    dh = (int)pow(10, floor(log10(a)));
    while(a){
        if(isPrime[a] != 0) return 0;
        a -= (a / dh) * dh;
        dh /= 10;
    }
    return 1;
}

int main(){
    init();
    int sum = 0, num = 0;
    for(int i = 1; i <= prime[0]; i++){
        if(prime[i] < 10) continue;
        if(is_need(prime[i])){
            printf("need %d\n", prime[i]);
            sum += prime[i];
            num += 1;
        }
        if(num == 11) break;
    }
    printf("%d %d %d\n", sum, num, prime[0]);
    return 0;
}
