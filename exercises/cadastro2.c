#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a[50], b[50];
    int cnt = 0, aux =0, f;
    struct endereco{
            char rua[50];
            int numero;
            char estado[50];
    };
    struct cadastro{
        char nome[50];
        int idade;
        float salario;
        struct endereco end;
    };
    struct cadastro cad[5];
    gets(a);
    do{
        if (strcmp(a,"inserir")==0){
            if(cnt !=5){
                //gets(cad[cnt].nome);
                scanf("%s %d %f %s %d %s", &cad[cnt].nome, &cad[cnt].idade, &cad[cnt].salario, &cad[cnt].end.rua, &cad[cnt].end.numero, &cad[cnt].end.estado);
                printf("Registro %s %d %.2f %s %d %s inserido\n", cad[cnt].nome, cad[cnt].idade, cad[cnt].salario, cad[cnt].end.rua, cad[cnt].end.numero, cad[cnt].end.estado);
                cnt++;
            }
            else{
                printf("Espaco insuficiente\n");
            }
        }
        else if (strcmp(a,"mostrar")==0){
            gets(b);
            f =0;
            for(aux=0; aux!=5; aux++){
                if (strcmp(cad[aux].nome, b)==0){
                    printf("Registro %s %d %.2f %s %d %s\n", cad[aux].nome, cad[aux].idade, cad[aux].salario, cad[aux].end.rua, cad[aux].end.numero, cad[aux].end.estado);
                }
                else{
                    f++;
                }
            }
            if(f==5){
                printf("Registro ausente\n");
            }
        }
        else if (strcmp(a,"alterar")==0){
            f =0;
            scanf("%s %d %f %s %d %s", &cad[5].nome, &cad[5].idade, &cad[5].salario, &cad[5].end.rua, &cad[5].end.numero, &cad[5].end.estado);
            for(aux=0; aux!=5; aux++){
                if (strcmp(cad[5].nome, cad[aux].nome)==0){
                    cad[aux].idade = cad[5].idade;
                    cad[aux].salario = cad[5].salario;
                    strcpy(cad[aux].end.rua, cad[5].end.rua);
                    cad[aux].end.numero = cad[5].end.numero;
                    strcpy(cad[aux].end.estado, cad[5].end.estado);
                    printf("Registro %s %d %.2f %s %d %s alterado\n", cad[aux].nome, cad[aux].idade, cad[aux].salario, cad[aux].end.rua, cad[aux].end.numero, cad[aux].end.estado);
                }
                else{
                    f++;
                }
            }
            if(f==5){
                printf("Registro ausente para alteracao\n");
            }
        }
    }while(gets(a)!= NULL);
    return 0;
}
