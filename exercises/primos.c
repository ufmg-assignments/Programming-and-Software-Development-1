#include <stdio.h>
#include <stdlib.h>

int primo(int a){
    unsigned long long int c;
    int res, con=0;
    for(c=1; c<=a/2; c++){
        if(a%c == 0)
            con++;
        if (con==2){
            break;
        }
    }
    if(con == 1){
        res = 1;
    }
    else{
        res = 0;
    }

    return res;
}

int main(){
    unsigned long long int pr;
    scanf("%llu", &pr);
    do{
        if(pr<=1){
            printf("-1\n");
        }
        else{
            printf("%d\n", primo(pr));
        }
    }while(scanf("%llu", &pr) != EOF);
    return 0;
}
