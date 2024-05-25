#include <stdio.h>

int main(){

    int a, b, c, con;
    scanf("%d", &a);
    scanf("%d", &b);
    while(a <=b){
        con = 0;
        for(c=1; c<=a/2; c++){
            if(a%c == 0)
                con++;
        }
        if(con == 1)
            printf("%d\n", a);
        a++;
    }
    return 0;
}
