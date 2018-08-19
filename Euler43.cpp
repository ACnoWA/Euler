/*************************************************************************
	> File Name: Euler43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 08时43分03秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <inttypes.h>

using namespace std;

int64_t is_need(int *a){
    //if(a[0] == 0) return 0 ;
    int64_t ret = a[0], num = 0;
    int p[7] = {2, 3, 5, 7, 11, 13, 17};
    for(int i = 1; i < 10; i++){
        ret = ret * 10 + a[i];
        num = num * 10 + a[i];
        if(i >= 3){
            if(num % p[i - 3] != 0) return 0;
            num = num % 100;
        }
    }
    return ret;
}

int main(){
    int a[10] = {0};
    int64_t sum = 0;
    for(int i = 0; i < 10; i++){
        a[i] = i;
    }
    do{
        sum += is_need(a);
    }while(next_permutation(a, a + 10));
    printf("%" PRId64 "\n", sum);
    return 0;
}
