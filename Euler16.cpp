/*************************************************************************
	> File Name: Euler16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 20时05分51秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 500

int num[MAX_N] = {1, 1};
//数组的第零位存大数的长度

int main(){
    //求2的1000次方等价于 2^10的100次方或2^10*2^10的50次方这样能减少循环次数
    //for(int i = 0; i < 100; i++){
        //  for(int j = 1; j <= num[0]; j++){
          //  num[j] *= 1024;
        //}
 //       for(int j = 1; j <= num[0]; j++){
 //           if(num[j] < 10) continue;
 //           num[j + 1] += num[j] / 10;
 //           num[j] %= 10;
 //           num[0] += (j == num[0]);
 //       }
 //   }
    for(int i = 0; i < 1000; i++){
        for(int j = 1; j <= num[0]; j++){
            num[j] *= 2;
        }
        for(int j = 1; j <= num[0]; j++){
            if(num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }
    int sum = 0;
    for(int i = num[0]; i > 0; i--){
         sum += num[i];
    }
    printf("%d\n", sum);
    return 0;
}
