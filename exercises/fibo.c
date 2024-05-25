#include <stdlib.h>
#include <stdio.h>

int fibo(int n){
    int f =0;
    if((n == 1) || (n ==2))
        f = 1;
    else
        f = fibo(n-1)+ fibo(n-2);
    return f;
}

int main(){
    int num =0;
    scanf("%d", &num);

    printf("%d", fibo(num));

    return 0;
}
