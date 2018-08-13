/*************************************************************************
	> File Name: Euler20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 20时20分10秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200

int num[MAX_N] = {1, 1};

int main(){
    for(int i = 2; i <= 100; i++){
        for(int j = 1; j <= num[0]; j++){
            num[j] *= i;
        }
        for(int j = 1; j <= num[0]; j++){
            if(num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            if(j == num[0]) num[0] += 1;
        }
    }
    int ans = 0;
    for(int i = 1; i <= num[0]; i++){
        ans += num[i];
    }
    printf("%d %d\n", ans, num[0]);
    return 0;
}
