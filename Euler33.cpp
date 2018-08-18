/*************************************************************************
	> File Name: Euler33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 17时18分43秒
 ************************************************************************/

#include <stdio.h>

int gca(int a, int b){
    if(b == 0) return a;
    return gca(b, a % b);
}

int is_curious(int a, int b){
    int tempa = a, tempb = b;
    int num[10] = {0};
    int ansa, ansb, x, y;
    if(a % 10 == 0 || b % 10 == 0) return 0;
    x = a % 10;
    num[x] = 1;
    a /= 10;
    num[a] = 1;
    y = b % 10;
    b /= 10;
    if(num[y] && num[b]) return 0;
    if(!num[y] && !num[b]) return 0;
    if(num[y]) {
        ansb = b;
        a == y ? ansa = x : ansa = a;    
    }
    if(num[b]){
        ansb = y;
        a == b ? ansa = x : ansa = a;
    }
    if((double)tempa/tempb != (double)ansa/ansb) return 0;
    else  return 1;
}

int main(){
    int numerator = 1, denominator = 1;
    for(int i = 10; i < 100; i++) {
        for(int j = i + 1; j < 100; j++){
            if(!is_curious(i, j)) continue;
            printf("%d %d\n",i ,j);
            numerator *= i;
            denominator *= j;
        }
    }
    printf("%d\n", denominator/gca(numerator, denominator));
    return 0;
}
