/*************************************************************************
	> File Name: Euler11.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 14时30分44秒
 ************************************************************************/

#include <stdio.h>
//方向数组，他的第一维代表方向的个数，第二维代表方向向量的维数
int dir_arr[4][2] = {
    1,1,1,-1,
    0,1,1,0
};

int main(){
    //开大一点 这样就可以避免边界的判断
    int num[30][30] = {0};
    int ans = 0;
    for(int i = 5; i < 25; i++ ){
        for(int j = 5; j < 25; j++){
            scanf("%d", num[i] + j);
        }
    }

    for(int x = 5; x < 25; x++){
        for(int y = 5; y < 25; y++){
            //第三层循环是遍历方向数组中的四个方向
            for(int k = 0; k < 4; k++) {
                int p = 1;
                //第四层循环是根据题意再该放方向上走四步
                for(int step = 0; step < 4; step++){
                    int xx = x + step * dir_arr[k][0];
                    int yy = y + step * dir_arr[k][1];
                    p *= num[xx][yy];
                }
                if (p > ans) ans = p;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

