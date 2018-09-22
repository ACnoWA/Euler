/*************************************************************************
> File Name: my_printf.c
> Author: Liyi
> Mail: 294225027@qq.com
> Created Time: 2018年09月20日 星期四 20时45分37秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <string.h>

int my_printf(const char *frm, ...) {
    int cnt;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        char str[1000];
                        int temp = va_arg(arg, int), x = 0; 
                        int i = 0, flag = 1, s = 0; 
                        if (temp < 0){
                            flag = 0;
                            if(temp == INT32_MIN) { 
                                s = 1; 
                                temp += 1;
                            }
                            temp *= -1;
                        }
                        while(temp){
                            str[i] = (temp % 10) + '0';
                            temp /= 10;
                            i++;
                        }
                        str[i] = '\0';
                        if(!flag) putchar('-');
                        for(int j = strlen(str); j >= 0; j--){
                            if (j == 0) {
                                str[j] += s; 
                                putchar(str[j]);
                            }else putchar(str[j]);
                        }
                        /* int zero = 0, flag = 1;
                        while (temp % 10 == 0) {
                        zero++;
                        temp /= 10;
                    }
                        while (temp) {
                        x = x * 10 + temp % 10;
                        temp /= 10;
                    }
                        if(x < 0){
                        flag = 0;
                        putchar('-');
                        x *= -1;
                    }
                        while (x) {
                        putchar(x % 10 + '0');
                        x /= 10;
                    }
                        for(int i = 0; i < zero; i++){
                        putchar('0');
                    }*/
                    } break;
                    default : 
                    fprintf(stderr, "error : unknow %%%c\n", frm[i]); 
exit(1);
}
} break;
default:
    putchar(frm[i]);

        }

    }
    return cnt;

}

int main() {
    int n = 123;
    my_printf("hello world\n");
    my_printf("n = %d\n", n);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;

}
