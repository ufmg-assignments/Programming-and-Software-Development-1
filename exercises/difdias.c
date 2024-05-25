#include <stdio.h>
#include <stdlib.h>

int dif(int a){
    int res;
    if ((a%4==0 && a%100!= 0) || a%400==0){
        return 1;
    }
    else{
        return 0;
    }
}

int data(int dia, int mes, int ano){
    int DIAS[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int aux, d=0, f, con;


    if(ano==2020){
        f=0;
        for(con=1; con!=mes; con++){
            f+=DIAS[con];
        }
        f+=dia;
        if(mes<3){
            f--;
        }
        d = 261-f;
    }

    else{
        d = 0;
        f=0;
        for(con=1; con!=mes; con++){
            f+=DIAS[con];
        }
        f+=dia;
        if(dif(ano)==1 && mes<3){
            d+=366-f;
        }

        else{
            d+=365-f;
        }

        for(con=ano+1; con!=2020; con++){
            if(dif(con)==1){
                d+=366;
            }
            else{
                d+=365;
            }
        }

        if(con==2020){
            d += 262;
        }
    }

    return d;
}

int main(){
    int mostrar=0;
    int di=0, me=0, an=0;
    scanf("%d %d %d", &di, &me, &an);
    do{
        mostrar = data(di, me, an);
        printf("%d\n", mostrar);
    }while(scanf("%d %d %d", &di, &me, &an)!= EOF);
    return 0;
}
