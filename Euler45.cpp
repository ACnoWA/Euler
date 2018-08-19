/*************************************************************************
	> File Name: Euler45.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 09时13分20秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t pentagonal(int64_t n){
    return n * (3 * n - 1) / 2;
}

int64_t hexagonal(int64_t n){
    return n * (2 * n - 1);
}

int64_t binary_search(int64_t (*num)(int64_t), int64_t n, int64_t x){
    int64_t head = 0, tail = n - 1, mid;
    while(head <= tail){
        mid = (head + tail) / 2;
        if(num(mid) == x) return mid;
        if(num(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main(){
    int64_t n = 144;
    while(binary_search(pentagonal, 2 * n, hexagonal(n)) == -1) n++;
    printf("%" PRId64 "\n", hexagonal(n));
    return 0;
}
