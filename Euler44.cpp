/*************************************************************************
	> File Name: Euler44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时54分45秒
 ************************************************************************/

#include <stdio.h>

int Pentagonal(int n){
    return n * (3 * n - 1) / 2;
}

int is_Pentagonal(int a){
    int head = 1, tail = 10000, mid;
    while(head <= tail){
        mid = (head + tail) / 2;
        if(Pentagonal(mid) == a) return mid;
        if(Pentagonal(mid) < a) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}


int main(){

    return 0;
}
