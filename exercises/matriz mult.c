#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime (int *v, int aux){
    for(int cont =0; cont!=aux; cont++){
        printf("%d ", v[cont]);
    }
    printf("\n");
}


void multiplica (int *v, int aux, double mlt){
    for(int cont =0; cont!=aux; cont++){
        v[cont]*= mlt;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int vetor[n];
    int cont;
    for (cont = 0; cont!=n; cont++){
        scanf("%d", &vetor[cont]);
    }

    double mult;
    scanf("%lf", &mult);

    imprime (vetor, n);
    multiplica (vetor, n,mult);
    imprime (vetor, n);
    multiplica (vetor, n, 1/mult);
    imprime (vetor, n);

    return 0;
}
