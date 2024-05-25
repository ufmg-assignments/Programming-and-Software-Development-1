#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//cria-se uma estrutura para receber os dados de cada funcionario
struct Func{
    char nome[100];
    double salario;
    int dia, mes, ano;
    char depart[100];
};

//declaracao das funcoes a serem implementadas
void exportar(struct Func f[], int n);
void listar(struct Func f[], int n, char dpt[50]);
void funcMaisAntigo(struct Func f[], int n);
void funcMaisAntigoDepart(struct Func f[], int n, char dpt[50]);
void mediaSal(struct Func f[], int n);
void mediaSalDepart(struct Func f[], int n, char dpt[50]);


int main(int argc, char *argv[]){
    //primeiramente, abre-se o arquivo em modo leitura
    FILE *arq;
    arq = fopen("tperro.txt", "r");

    //le-se o numero de funcionarios e entao é criado um vetor de struct de acordo com esse numero
    int qntd;
    fscanf(arq,"%d\n", &qntd);
    struct Func funcionarios[qntd];

    //para automatizar a leitura de dados para qualquer arquivo desse tipo, utiliza-se um for
    for(int aux = 0; aux!=qntd; aux++){
        fgets(funcionarios[aux].nome, 40, arq);
        funcionarios[aux].nome[strlen(funcionarios[aux].nome) -1] = '\0';
        fscanf(arq,"%lf\n", &funcionarios[aux].salario);
        fscanf(arq,"%d/%d/%d\n", &funcionarios[aux].dia, &funcionarios[aux].mes, &funcionarios[aux].ano);
        fscanf(arq,"%s\n", &funcionarios[aux].depart);
    }

    //comando para fechar o arquivo
    fclose(arq);

    int funcao=2;
    if(funcao==1){
        exportar(funcionarios, qntd);
    }
    else if(funcao==2){
        listar(funcionarios, qntd, "PD");
    }
    else if(funcao==3){
        funcMaisAntigo(funcionarios, qntd);
    }
    else if(funcao==4){
        funcMaisAntigoDepart(funcionarios, qntd, "Administrativo");
    }
    else if(funcao==5){
        mediaSal(funcionarios, qntd);
    }
    else if(funcao==6){
        mediaSalDepart(funcionarios, qntd, "PD");
    }
    return 0;
}

void exportar(struct Func f[], int n){
    int ordenar[n];

    FILE *exp;
    exp = fopen("exportar.txt", "w");

    for(int aux=0; aux!=n; aux++){
        int det =0;
        for(int cnt=0; cnt!=n; cnt++){
            if(strcmp(f[aux].nome, f[cnt].nome)==1){
                det++;
            }
            ordenar[aux] = det;
        }
    }

    for(int aux=0; aux!=n; aux++){
        for(int cnt=0; cnt!=n; cnt++){
            if(ordenar[cnt]==aux){
                fprintf(exp, "%s\n%.2lf\n%02d/%02d/%04d\n%s\n", f[cnt].nome, f[cnt].salario,f[cnt].dia, f[cnt].mes,f[cnt].ano, f[cnt].depart);
            }
        }
    }

    fclose(exp);
}

void listar(struct Func f[], int n, char dpt[50]){
    int ordem[n];

    for(int aux=0; aux!=n; aux++){
        int det =0;
        for(int cnt=0; cnt!=n; cnt++){
            if(strcmp(f[aux].nome, f[cnt].nome)==1){
                det++;
            }
            ordem[aux] = det;
        }
    }

    for(int aux=0; aux!=n; aux++){
        for(int cnt=0; cnt!=n; cnt++){
            if(ordem[cnt]==aux && strcmp(f[cnt].depart,dpt)==0){
                printf("%s\n%.2lf\n%02d/%02d/%04d\n%s\n", f[cnt].nome, f[cnt].salario,f[cnt].dia, f[cnt].mes,f[cnt].ano, f[cnt].depart);
            }
        }
    }
}

void funcMaisAntigo(struct Func f[], int n){
    int identificador =0;
    int anoaux = f[0].ano, mesaux = f[0].mes, diaaux = f[0].dia;

    for(int aux=1; aux!=n; aux++){
        if(f[aux].ano> anoaux){
            continue;
        }
        else if(f[aux].ano< anoaux){
            identificador =aux;
            anoaux = f[aux].ano;
            mesaux = f[aux].mes;
            diaaux = f[aux].dia;
        }
        else{
            if(f[aux].mes >mesaux){
                continue;
            }
            else if(f[aux].mes < mesaux){
                identificador=aux;
                anoaux = f[aux].ano;
                mesaux = f[aux].mes;
                diaaux = f[aux].dia;
            }
            else{
                if(f[aux].dia >diaaux){
                    continue;
                }
                else{
                    identificador = aux;
                    anoaux = f[aux].ano;
                    mesaux = f[aux].mes;
                    diaaux = f[aux].dia;
                }
            }
        }

    }
    printf("%s\n%.2lf\n%02d/%02d/%04d\n%s", f[identificador].nome, f[identificador].salario,f[identificador].dia, f[identificador].mes,f[identificador].ano, f[identificador].depart);
}

void funcMaisAntigoDepart(struct Func f[], int n, char dpt[50]){
    int identificador =0;
    int anoaux, mesaux, diaaux, aux;

    //primeiro iniciamos as variaveis auxiliares com o primeiro funcionario encontrado que pertence ao departamento
    for(aux=0; aux!=n; aux ++){
        if(strcmp(f[aux].depart,dpt)==0){
            anoaux = f[aux].ano;
            mesaux = f[aux].mes;
            diaaux = f[aux].dia;
            break;
        }
    }

    //em sequida comparamos com o restante. Por otimizacao, continuamos de onde o contador auxiliar parou.
    for(aux; aux!=n; aux++){
        //o funciario deve ser do departamento passado como parametro:
        if(strcmp(f[aux].depart,dpt)==0){
            if(f[aux].ano> anoaux){
                continue;
            }
            else if(f[aux].ano< anoaux){
                identificador =aux;
                anoaux = f[aux].ano;
                mesaux = f[aux].mes;
                diaaux = f[aux].dia;
            }
            else{
                if(f[aux].mes >mesaux){
                    continue;
                }
                else if(f[aux].mes < mesaux){
                    identificador=aux;
                    anoaux = f[aux].ano;
                    mesaux = f[aux].mes;
                    diaaux = f[aux].dia;
                }
                else{
                    if(f[aux].dia >diaaux){
                        continue;
                    }
                    else{
                        identificador = aux;
                        anoaux = f[aux].ano;
                        mesaux = f[aux].mes;
                        diaaux = f[aux].dia;
                    }
                }
            }
        }
    }
    printf("%s\n%.2lf\n%02d/%02d/%04d\n%s", f[identificador].nome, f[identificador].salario,f[identificador].dia, f[identificador].mes,f[identificador].ano, f[identificador].depart);
}

void mediaSal(struct Func f[], int n){
    double soma=0;
    //inicialmente, acumula-se o salario total
    for(int aux=0; aux!=n; aux++){
        soma+=f[aux].salario;
    }
    //a media sera a divisao da soma total pelo numero de funcionarios
    double media = soma/ (double) n;
    printf("%.2lf", media);
}

void mediaSalDepart(struct Func f[], int n, char dpt[50]){
    double soma=0;
    int cnt=0;
    for(int aux=0; aux!=n; aux++){
        //agora so sera considerado os salarios dos funcionarios de determinado departamento passado como parametro
        if(strcmp(f[aux].depart,dpt)==0){
            soma+=f[aux].salario;
            //tambem so serao contabilizados para realizar a media os funcionarios do mesmo departamento
            cnt++;
        }
    }
    double media = soma/ (double) cnt;
    printf("%.2lf", media);
}
