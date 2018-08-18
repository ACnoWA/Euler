/*************************************************************************
	> File Name: Euler34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 22时04分05秒
 ************************************************************************/

#include <stdio.h>
#define Max 2540160

//int arr[10] = {1,1,2,6,24,120,720, 5040,40320,362880};
int factor(int b){
    int sum = 1;
    while(b){
        sum *= b--;
    }
    return sum;
}

int is_curious(int a){
    int temp = a, num = 0;
    while(a){
        //num += arr[a % 10];
        num += factor(a % 10);
        a /= 10;
    }
    return temp == num;
}

int main(){
    int ans = 0;
    for(int i = 3; i <=  Max; i++){
        if(!is_curious(i))  continue;
        ans += i;
    }
    printf("%d\n",ans);
    return 0;
}
