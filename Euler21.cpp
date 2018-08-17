/*************************************************************************
	> File Name: Euler21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 16时15分36秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};
//is_prime存储数字i中最小素因子的幂次值
int is_prime[MAX_N + 5] = {0};
int d[MAX_N + 5] = {0};

void init(){
    for(int i = 2; i < MAX_N; i++){
        if(!is_prime[i]) {
            prime[++prime[0]] = i;
            d[i] = i + 1;
            is_prime[i] = i;
        }
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] >= MAX_N) break;
            is_prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
             is_prime[i * prime[j]] =  is_prime[i] * prime[j];
            //由于i * prime[j] 与 i相差i中的一个最小素因子，运用公式
              d[i * prime[j]] = d[i] * 
                (is_prime[i] * prime[j] * prime[j] - 1) /
                (is_prime[i] * prime[j] - 1);
             break;   
            }else{
                is_prime[i * prime[j]] = prime[j];
                d[i * prime[j]] = d[i] * d[prime[j]];
            }
        }
    }

    for(int i = 2; i < MAX_N; i++)
        d[i] -= i;
}



int main(){
    init();
    int sum = 0;
    for(int i = 0; i < MAX_N; i++){
        if(d[i] <= MAX_N && d[i] != i && d[d[i]] == i){
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
