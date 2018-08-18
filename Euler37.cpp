/*************************************************************************
	> File Name: Euler37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 22时12分35秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define RANGE 7000

int isPrime[RANGE] = {0};
int prime[RANGE] = {0};

/*void init(){
    for(int i = 2; i <= RANGE; i++){
        if(!isPrime[i])
            prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] >= RANGE) break;
            isPrime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}*/

void init(){
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
}

int is_need(int a){
    if(isPrime[a]) return 0;
    int temp = a, dh;
    while(a){
        a /= 10;
        if(isPrime[a] != 0) return 0;
    }
    a = temp;
    dh = (int)pow(10,floor(log10(a)));
    while(a){
        a -= (a / dh) * dh;
        dh /= 10;
        if(isPrime[a] != 0) return 0;
    }
    return 1;
}

int main(){
    init();
    int sum = 0, num = 0;
    for(int i = 1; i <= prime[0]; i++){
        printf("%d\n", prime[i]);
        if(is_need(prime[i]) == 1){
            sum += prime[i];
            num++;
        }
        if(num == 11) break;
    }
    printf("%d\n", sum);
    return 0;
}
