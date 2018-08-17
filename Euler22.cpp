/*************************************************************************
	> File Name: Euler22.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 20时31分55秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <inttypes.h>
#include <algorithm>
#include "Euler22.h"

int main(){
    int i = 0, sum;
    int64_t ans = 0;
    while(nameArr[i++].length() != 0);
    std::sort(nameArr, nameArr + i - 1);
    i = 0;
    while(nameArr[i].length() != 0){
        sum = 0;
        for(int j = 0; j < nameArr[i].length(); j++){
            sum += nameArr[i][j] - 'A' + 1;
        }
        ans += sum * (++i);
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
