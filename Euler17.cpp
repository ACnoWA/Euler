/*************************************************************************
	> File Name: Euler17.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 15时58分58秒
 ************************************************************************/

#include <stdio.h>

int num[20] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
int arr[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

int get_num(int i){
    int temp;
    if(i < 20) return num[i];
    else if(i < 100){
        return arr[i / 10] + num[i % 10];
    }else if(i < 1000){
        temp = get_num(i % 100);
        if(temp != 0) temp += 3;
        return temp + num[i / 100] + 7;
    }else if(i == 1000){
        return 11;
    }
    return 0;
}

int main(){
    int sum = 0;
    for(int i = 1; i <= 1000; i++){
        sum += get_num(i);
    }
    printf("%d\n", sum);
    return 0;
}
