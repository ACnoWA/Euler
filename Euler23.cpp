/*************************************************************************
	> File Name: Euler23.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 15时56分54秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 30000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};
int d[MAX_N + 5] = {0};
int full[MAX_N + 5] = {0};

void init(){
    for(int i = 2; i < MAX_N; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            d[i] = i + 1;
            is_prime[i] = i;
        }
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] >= MAX_N) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                is_prime[i * prime[j]] = is_prime[i] * prime[j];
                d[i * prime[j]] = d[i] * 
                (1 - is_prime[i] * prime[j] * prime[j]) / (1 - is_prime[i] * prime[j]);
                break;
            }else{
                is_prime[i * prime[j]] = prime[j];
                d[i * prime[j]] = d[i] * d[prime[j]];
            }
        }
    }

    for(int i = 2; i < MAX_N; i++){
        d[i] -= i;
        if(d[i] > i){
            full[++full[0]] = i;
        }
    }
}


int is_full(int a){
    int head = 1, tail = full[0], mid;
    while(head <= tail){
        mid = (head + tail) / 2;
        if(full[mid] == a) return 1;
        if(full[mid] < a) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int is_need(int n){
    for(int i = 1; i <= full[0]; i++){
        if(is_full(n - full[i]) && (n - full[i]) >= full[1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    init();
    int ans = 0;
    for(int i = 1; i < 24; i++){
        ans += i;
    }
    for(int i = 25; i <= 28123; i++){
        ans += i * is_need(i);
    }
    printf("%d\n", ans);
    return 0;
}
