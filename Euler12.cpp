/*************************************************************************
	> File Name: Euler12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 10时11分19秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N  1000000

int prime[MAX_N] = {0};
//该数组表示i的约数个数
int dnum[MAX_N] = {0};
//该数组表示i的最小素因子的幂次
int mnum[MAX_N] = {0};

void init(){
    for(int i = 2; i <= MAX_N; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
    }
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] >= MAX_N) break;
            prime[i * prime[j]] = 1;
            //当两数不互质 此时由于线性筛的性质prime[j]是i的最小素因子，i的约数个数可以表示为Ｍ*(bj + 1)　则i*prime[j]的约数等于M*(bj + 2)，而mnum[i]中存储的就是bj
            if( i % prime[j] == 0){
                //因为i能整除prime[j],说明i*prime[j]这个数的最小素因子幂次不只为１，在i中还含有
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            }
            //当两数互质时，利用约数公式,同时也说明prime[j]就是i*prime[j]的最小素因子，否则如果i中含prime[j],i能整除prime[j];
            else{ 
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
    return;
}

int factor_nums(int n){
    if(n & 1){
        return dnum[n] * dnum[(n + 1) / 2];
    }
    return dnum[n / 2] * dnum[n + 1];
    
}

int main(){
    init();
    int i = 1;
    while(factor_nums(i) <= 500) i++;
    printf("%d\n", i * (i + 1) / 2);
    return 0;
}
