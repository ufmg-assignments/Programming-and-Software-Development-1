#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a[50], b[50];
    int cnt = 0, aux =0, f;
    struct cadastro{
        char nome[50];
        int idade;
        float salario;
    };
    struct cadastro cad[4];
    gets(a);
    do{
        if (strcmp(a,"inserir")==0){
            if(cnt !=4){
                //gets(cad[cnt].nome);
                scanf("%s %d %f",&cad[cnt].nome, &cad[cnt].idade, &cad[cnt].salario);
                printf("Registro %s %d %.2f inserido\n", cad[cnt].nome, cad[cnt].idade, cad[cnt].salario);
                cnt++;
            }
            else{
                printf("Espaco insuficiente\n");
            }
        }
        else if (strcmp(a,"mostrar")==0){
            gets(b);
            f =0;
            for(aux=0; aux!=4; aux++){
                if (strcmp(cad[aux].nome, b)==0){
                    printf("Registro %s %d %.2f\n", cad[aux].nome, cad[aux].idade, cad[aux].salario);
                }
                else{
                    f++;
                }
            if(f==4){
                printf("Registro ausente\n");
            }
            }
        }
    } while(gets(a)!= NULL);
    printf("%s", a);
    return 0;
}
