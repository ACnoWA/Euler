/*************************************************************************
	> File Name: Euler49.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 10时22分45秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000000

int prime[MAX_N] = {0};

void init(){
    for(int i = 2; i < MAX_N; i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] >= MAX_N) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int main(){
    init();
    int start = 0, end = 0;
    int flag = 1;
    for(int i = 1; i <= prime[0]; i++){
        if(prime[i] > 1000 && flag){
            start = i;
            flag = 0;
        }
        if(prime[i] > 10000)
        {
            end = i;
            break;
        }
    }
    for(int i = start; i < end; i++){
        int num[10] = {0}, arr[4] = {0};
        int temp = prime[i];
        while(temp){
            num[temp % 10] = 1;
            temp /= 10;
        }
        for(int j = i + 1; j < end; j++){
           int flag = 1;
            temp = prime[j];
            while(temp){
                if(!num[temp % 10]){
                    flag = 0;
                    break;
                }
                num[temp % 10]++;
                temp /= 10;
            }
            for(int l = 0; l < 10; l++){
                if(num[l] == 0 || num[l] == 2);
                else flag = 0;
            }
            if(!flag) continue;
            for(int k = j + 1; k < end; k++){
                int flag1 = 1;
                temp = prime[k];
                while(temp){
                    if(!num[temp % 10]){
                        flag1 = 0;
                        break;
                    }
                    num[temp % 10]++;
                    temp /= 10;
                }
                for(int l = 0; l < 10; l++){
                    if(num[l] == 0 || num[l] == 3);
                    else flag1 = 0;
                }
                if(!flag1) continue;
                else{
                    if(prime[j] - prime[i] == prime[k] - prime[j]){
                        printf("%d %d %d\n", prime[i], prime[j], prime[k]);
                    }
                }
            }
        }
    }
    return 0;
}
