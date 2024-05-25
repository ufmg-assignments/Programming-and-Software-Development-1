#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void media(double vet[], int n, int *i){
    double med=0, soma =0, comp, comp2=0;
    int cnt=0, aux, resultado =0;
    for(cnt=0; cnt!=n; cnt++){
        soma+= vet[cnt];
    }
    med = soma/ (double) n;
    comp = fabs(vet[0]-med);
    i = 0;
    for(cnt=1; cnt!=n; cnt++){
        comp2 = fabs(vet[cnt]-med);
        if(comp2<comp){
            comp = comp2;
            aux = cnt;
        }
        i = &aux;
    }

    printf("%d", *i);
}

int main(){
    int qnt =0, cnt=0;
    int *p;
    scanf("%d", &qnt);
    double aux[qnt], *pont;
    for (cnt = 0; cnt != qnt; cnt++){
        scanf("%lf", &aux[cnt]);
    }
    media(aux, qnt, p);
    return 0;
}
