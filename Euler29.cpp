/*************************************************************************
	> File Name: Euler29.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 10时40分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10000
#define MAX_M 201

int *result[MAX_N] = {0};
int result_length = 0;

int find_result(int * temp){
    for(int i = 0; i < result_length; i++){
        if(memcmp(result[i], temp, sizeof(int ) * MAX_M)) continue;
        return i + 1;
    }
    return 0;
}

int *calcu_num(int a, int b){
    int *temp = (int *)calloc(sizeof(int),  MAX_M);
    temp[0] = temp[1] = 1;
    for(int i = 0; i < b; i++){
        for(int j = 1; j <= temp[0]; j++) temp[j] *= a;
        for(int j = 1; j <= temp[0]; j++){
            if(temp[j] < 10) continue;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
            temp[0] += (j == temp[0]);
        }
    }
    return temp;
}

int main(){
    for(int i = 2; i <= 100; i++){
        for(int j = 2; j <= 100; j++){
            int *temp = calcu_num(i, j);
            if(find_result(temp) == 0){
                result[result_length++] = temp;
            }else{
                free(temp);
            }
        }
    }
    printf("%d\n", result_length);
    return 0;
}
