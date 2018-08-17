/*************************************************************************
	> File Name: Euler26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 09时52分13秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 1000
int dnum[MAX_N];

int get_length(int d){
    int y = 1, n = 1;
    memset(dnum, 0, sizeof(dnum));
    //printf("1 / %d = 0.", d);
    while(y != 0 && dnum[y] == 0){
        //求出商的每一位
        //printf("%d",y * 10 / d);
        //记录余数出现再第几位
        dnum[y] = n;
        //不断的求商上一位后的余数
        y = y * 10 % d;
        n += 1;
    }
    //如果循环结束时余数为0，则代表除尽了
    return y ? n - dnum[y] : 0;

}
int main(){
    int ans = 0, max_length = 0;
    for(int d = 2; d < 1000; d++){
        int temp_length = get_length(d);
        if(temp_length > max_length){
            max_length = temp_length;
            ans = d;
        }
    }
    printf("%d -> %d\n", ans, max_length);

    return 0;
}
