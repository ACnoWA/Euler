/*************************************************************************
	> File Name: Euler49-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时15分58秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#define MAX_N 10000

typedef struct{
    int num;
    //value表示素数的次数表示数
    int val;
}Node;

Node prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};
int cnt = 0;

int get_value(int n){
    int ret = 0;
    while(n){
        //数字Ｎ中每出现一次数字i，就在二进制表示的2*i + 1位上加１
        ret += 1 << ((n % 10) * 2);
        n /= 10;
    }
    return ret;
}

void init(){
    for(int i = 2; i * i < MAX_N; i++){
        if(is_prime[i]) continue;
        for(int j = i * i; j < MAX_N; j += i){
            is_prime[j] = 1;
        }
    }

    for(int i = 2; i < MAX_N; i++){
        if(!is_prime[i]){
            prime[cnt].num = i;
            prime[cnt].val = get_value(i);
            cnt++;
        }
    }
}

int main(){
    init();
    std::sort(prime, prime + cnt, [](Node &a, Node &b){
        if(a.val < b.val) return true;
        if(a.val == b.val &&  a.num < b.num) return true;
        return false;
    });

    for(int i = 0; i < cnt; i++){
        for(int j = i + 1; j < cnt && prime[i].val == prime[j].val; j++){
            int k = j + 1;
            while(k < cnt && prime[k].val == prime[j].val){
                int val1 = prime[k].num - prime[j].num;
                int val2 = prime[j].num - prime[i].num;
                if(val1 > val2) break;
                if(val1 == val2){
                    printf("%d%d%d\n", prime[i].num, prime[j].num, prime[k].num);
                }
                k += 1;
            }
        }
    }

    return 0;
}
