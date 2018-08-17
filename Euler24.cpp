/*************************************************************************
	> File Name: Euler24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 16时47分39秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10

//该数组存的每当数字中的i变化时，会产生几种状态变化
int jnum[MAX_N] = {0};
//dnum数组表示该位数字是否用过，1表示未用过
int dnum[MAX_N] = {0};

void init(){
    jnum[0] = dnum[0] = 1;
    for(int i = 1; i < MAX_N; i++){
        dnum[i] = 1;
        jnum[i] = i * jnum[i - 1];
    }
}

//该函数传入当前位置后还有几个数字n,这就可以知道该位跳1状态变化数是多少
//以及传入要跳转的状态数
int judge_num(int n, int k){
    //这个index可以这样理解，设想输出0-n的最小数字，就是从小到大依次找第一个未用到的数字，而在本题中当某一位上的数字发生跳动，所以ind = k / jnum[n] + 1;
    int ind = k / jnum[n] + 1, i = -1;
    while(ind > 0){
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}

int main(){
    init();
    int n, k;
    scanf("%d %d", &n, &k);
    k -= 1;
    //从最高位开始找，这样能保证从小到大
    for(int i = n - 1; i >= 0; i--){
        int num = judge_num(i, k);
        printf("%d ", num);
        k %= jnum[i];
    } 
    printf("\n");
    return 0;
}
