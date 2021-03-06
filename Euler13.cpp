/*************************************************************************
	> File Name: Euler13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 16时43分02秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char num[55];
//利用数组的第零位存数的长度
int ans[55] = {1, 0};

int main(){
    for(int i = 0; i < 100; i++){
        scanf("%s", num);
        int len = strlen(num);
        if(ans[0] < len) ans[0] = len;
        for(int j = 0; j <len; j++){
            //注意这个，用字符数组读入数时，高位存在了数组的低位，所以要将字符数组的数倒过来加
            ans[len - j] += (num[j] - '0');
        }
        //加完了之后对每一位上进行进位处理
        for(int j = 1; j <=  ans[0]; j++){
            if(ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    for(int i = ans[0]; i > ans[0] - 10; i--){
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
