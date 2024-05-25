#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    int a, aux=0, idaux=0;
    char arquivo[100], nomaux[50], telaux[20], str[20];
    char lin[200];
    struct contato{
            char nome[50];
            int idade;
            char telefone[20];
    };
    struct contato agenda[100];

    for(a=0;a!=100;a++){
        strcpy(agenda[a].nome ,"Vazio");
        agenda[a].idade = 0;
        strcpy(agenda[a].telefone, "Vazio");
    }


    gets(arquivo);
    FILE *f;
    f = fopen(arquivo, "rb");
    int i = 0;
    while(fread(&agenda[i], sizeof(agenda), 1, f) ==1){
        i++;
    }
    fclose(f);


    gets(lin);
    do{
        if(strcmp(lin,"Inserir")==0){
            aux = 0;
            scanf("%s %d %s", &nomaux, &idaux, &telaux);
            for (a=0;a!=100;a++){
                if(strcmp(agenda[a].nome,"Vazio")==0){
                    aux=1;
                    strcpy(agenda[a].nome, nomaux);
                    agenda[a].idade=idaux;
                    strcpy(agenda[a].telefone, telaux);
                    printf("Registro %s %d %s inserido\n", nomaux, idaux, telaux);
                    break;
                }
            }
            if(aux==0){
                printf("Espaco insuficiente\n");
            }
        }

        else if(strcmp(lin,"Alterar")==0){
            aux =0;
            scanf("%s %d %s", &nomaux, &idaux, &telaux);
            for (a=0;a!=100;a++){
                if(strcmp(agenda[a].nome,nomaux)==0){
                    aux=1;
                    strcpy(agenda[a].nome, nomaux);
                    agenda[a].idade=idaux;
                    strcpy(agenda[a].telefone, telaux);
                    printf("Registro %s %d %s alterado\n", nomaux, idaux, telaux);
                    break;
                }
            }
            if(aux==0){
                printf("Registro %s invalido\n", nomaux);
            }
        }

        else if(strcmp(lin,"Exibir")==0){
            aux = 0;
            gets(str);
            for(a=0;a!=100;a++){
                if(strcmp(str,agenda[a].nome)==0){
                    aux =1;
                    printf("Registro %s %d %s exibido\n", agenda[a].nome, agenda[a].idade, agenda[a].telefone);
                    break;
                }
            }
            if(aux==0){
                printf("Registro %s invalido\n", str);
            }
        }

        else if(strcmp(lin,"Excluir")==0){
            aux = 0;
            gets(str);
            for(a=0;a!=100;a++){
                if(strcmp(str,agenda[a].nome)==0){
                    aux=1;
                    printf("Registro %s %d %s excluido\n", agenda[a].nome, agenda[a].idade, agenda[a].telefone);
                    strcpy(agenda[a].nome, "Vazio");
                    agenda[a].idade=0;
                    strcpy(agenda[a].telefone, "Vazio");
                    break;
                }
            }
            for(a=0;a!=100;a++){
                if(strcmp(str,agenda[a].nome)==0){
                    strcpy(agenda[a].nome, "Vazio");
                    agenda[a].idade=0;
                    strcpy(agenda[a].telefone, "Vazio");
                    break;
                }
            }
            if(aux==0){
                printf("Registro %s invalido\n", str);
            }
        }
    }while(gets(lin)!= NULL);

    return 0;
}
