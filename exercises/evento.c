#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {janeiro = 1, fevereiro, marco, abril, maio, junho, julho, agosto, setembro, outubro, novembro, dezembro}meses;

typedef struct{
    int dia;
    meses mes;
    int ano;
}Data;

typedef struct{
    char nome[100];
    char local[100];
    Data dat;
}Evento;


void cadastrar_eventos(Evento a[], int n){
    for(int cnt = 0; cnt!=n; cnt++){
        scanf("%s %s %d %d %d", &a[cnt].nome, &a[cnt].local, &a[cnt].dat.dia, &a[cnt].dat.mes, &a[cnt].dat.ano);
    }
}

void imprimir_eventos(Evento a[], Data *d, int n){
    int aux=0;
    for(int cnt = 0; cnt!=n; cnt++){
        if (a[cnt].dat.dia == d->dia && a[cnt].dat.mes == d->mes && a[cnt].dat.ano ==d->ano){
            printf("%s %s\n", a[cnt].nome, a[cnt].local);
            aux++;
        }
    }
    if(aux==0){
        printf("Nenhum evento encontrado!");
    }
}


int main(){
    int n;
    scanf("%d", &n);
    Evento agenda[n];
    cadastrar_eventos(agenda, n);

    Data dt;
    scanf("%d", &dt.dia);
    scanf("%d", &dt.mes);
    scanf("%d", &dt.ano);

    imprimir_eventos(agenda, &dt,n);

    return 0;
}
