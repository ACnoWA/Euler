/*************************************************************************
	> File Name: Euler14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 15时13分29秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 1000000
#define KEEP_RANGE 1000000
//记忆化搜索：将算过的存起来

int keep_ans[KEEP_RANGE + 5] = {0};

int get_length(int64_t a){
    if(a == 1) return 1;
    if(a <= KEEP_RANGE && keep_ans[a]) return keep_ans[a];
    int temp_ans;
    if(a & 1) temp_ans = get_length(3 * a + 1) + 1;
    else temp_ans = get_length(a >> 1) + 1;//位运算，折半
    if(a <= KEEP_RANGE) keep_ans[a] = temp_ans;
    return temp_ans;
}

int main(){
    int ans = 0, ans_length = 0;
    for(int i = 1; i < MAX_N; i++){
        int temp_length = get_length(i);
        if(temp_length > ans_length){
            ans = i;
            ans_length = temp_length;
        }
    }
    printf("%d(%d)\n", ans,  ans_length);
    return 0;
}
