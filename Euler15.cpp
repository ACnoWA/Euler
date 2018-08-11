/*************************************************************************
	> File Name: Euler15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 11时50分58秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>


int main(){
    int64_t ans = 1, m = 20;
    for(int i = 40; i > 20; i--){
        ans *= i;
        while(ans % m == 0 && m != 1){
            ans /= m;
            m--;
        }
    }
    printf("%" PRId64 "\n", ans);
    return 0;
} 
