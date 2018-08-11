/*************************************************************************
	> File Name: Euler10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 17时55分18秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 2000000

int prime[MAX_N + 5] = {0};

int main(){
    int64_t sum = 0;
    for(int i = 2; i <= MAX_N; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
        }
        //注意判断条件中的prime[j] * i <= MAX_N,否则再会造成下标越界
        for(int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++){
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }    
    for(int i = 1; i <= prime[0]; i++)
      sum += prime[i];
    printf("%" PRId64 "\n", sum);
    return 0;
}
