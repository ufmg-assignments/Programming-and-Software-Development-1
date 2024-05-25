#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    double csep;
    double lsep;
    double cpet;
    double lpet;
    char tipo[50];
}Iris;

void classificar(Iris ni, Iris ri[], int n){
    char t[50];
    double menor;
    int cnt;
    menor = 1000000;

    for(cnt = 0; cnt!=n; cnt++){
        if((pow((ri[cnt].cpet - ni.cpet),2)+pow((ri[cnt].csep - ni.csep),2)+pow((ri[cnt].lsep - ni.lsep),2)+pow((ri[cnt].lpet - ni.lpet),2))<menor){
            menor = (pow((ri[cnt].cpet - ni.cpet),2)+pow((ri[cnt].csep - ni.csep),2)+pow((ri[cnt].lsep - ni.lsep),2)+pow((ri[cnt].lpet - ni.lpet),2));
            strcpy(t,ri[cnt].tipo);
        }
    }

    printf("%s", t);
}

int main(){
    int n;
    scanf("%d", &n);
    Iris flores[n];
    int cont;
    for(cont =0; cont!=n; cont++){
        scanf("%lf", &flores[cont].csep);
        scanf("%lf", &flores[cont].lsep);
        scanf("%lf", &flores[cont].cpet);
        scanf("%lf", &flores[cont].lpet);
        scanf("%s", &flores[cont].tipo);
    }
    Iris flord;
    scanf("%lf", &flord.csep);
    scanf("%lf", &flord.lsep);
    scanf("%lf", &flord.cpet);
    scanf("%lf", &flord.lpet);

    classificar(flord, flores, n);

    return 0;
}
