#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Struct que armazernara os dados das pessoas.
struct Pessoa{
    char nome[100];
    int idade;
    struct Pessoa *filho;
    int numFilhos;
};

//Funcoes a serem implementadas
struct Pessoa* buscaPessoa(struct Pessoa *pessoaAsc, char nomeProcurado[], int nivel, int imprimeNivel);
void liberarMemoria(struct Pessoa *pessoaAsc);

int main(){
    //PRIMEIRA PARTE
    int n=0;
    //Primeiramente, lemos o numero de pessoas que compoem a arvore genealogica
    scanf("%d", &n);

    //SEGUNDA PARTE
    //o primeiro a ser digitado sera sempre o ancestral mais velho
    struct Pessoa* ancestral;
    ancestral = (struct Pessoa *) malloc(sizeof(struct Pessoa));
    char var[10];
    scanf("%s %d %s", ancestral->nome, &ancestral->idade, var);
    ancestral->filho = (struct Pessoa *) malloc(sizeof(struct Pessoa));
    ancestral->numFilhos =0;

    //Em seguida lemos os demais membros da familia, identificando seu pai ou sua mae com a funcao recursiva implementada
    for(int i =1; i!=n; i++){

        char nome1[100], parente[100];
        int idade1=0;
        scanf("%s %d %s", nome1, &idade1, parente);
        struct Pessoa *pai = buscaPessoa(ancestral, parente, 0, 0);

        //Se for o primeiro filho, alocamos a memoria referente a uma struct do tipo Pessoa
        if(pai->numFilhos ==0){
            pai->numFilhos++;
            pai->filho = (struct Pessoa *) malloc(sizeof(struct Pessoa));
            pai->filho[0].idade = idade1;
            pai->filho[0].numFilhos = 0;
            strcpy(pai->filho[0].nome, nome1);
        }
        //se nao for o primeiro filho, realocamos a memoria de acordo com o numero atualizado de filhos do progenitor achado
        else{
            pai->numFilhos++;
            pai->filho = realloc(pai->filho, pai->numFilhos*sizeof (struct Pessoa));
            pai->filho[pai->numFilhos-1].idade = idade1;
            pai->filho[pai->numFilhos-1].numFilhos = 0;
            strcpy(pai->filho[pai->numFilhos-1].nome, nome1);
        }
    }

    //TERCEIRA PARTE
    int consultas=0;
    //Agora, le-se o numero de consultas a serem realizadas na arvore genealogica
    scanf("%d", &consultas);

    //QUARTA PARTE
    for(int i=0; i!=consultas; i++){
        char p1[100], p2[100];
        scanf ("%s %s", p1, p2);
        //Primeiro, identificamos a struct referente a pessoa mais proxima do ancestral mais antigo
        struct Pessoa *progenitor = buscaPessoa(ancestral, p2, 0, 0);
        //Em seguida, passamos esse "progenitor" achado e a pessoa mais nova como parametros para a mesma funcao,
        //mas agora com funcionalidade alterada: ela devera imprimir o nivel de parentesco entre eles
        buscaPessoa(progenitor, p1, 0, 1);
    }

    //QUINTA PARTE -> FUNCAO "buscaPessoa" usada na segunda e na quarta parte esta implementada logo apos a main

    //SEXTA PARTE
    //Para liberar a memoria alocada, chamamos a funcao recursiva "liberarMemoria" com o ancestral mais antigo como parametro
    //Essa funcao esta implementada logo apos a funcao "buscaPessoa"
    liberarMemoria(ancestral);
    //Por fim, libera-se a memoria alocada ao ancestral mais antigo:
    free(ancestral);

    return 0;
}

struct Pessoa* buscaPessoa(struct Pessoa *pessoaAsc, char nomeProcurado[], int nivel, int imprimeNivel){
    //PRIMEIRA FUNCIONALIDADE DA QUINTA PARTE
    if (imprimeNivel==0){
        //Caso base da funcao recursiva sera retornar a struct referente a pessoa procurada
        if(strcmp(pessoaAsc->nome,nomeProcurado)==0){
            return pessoaAsc;
        }
        // A recursao ira percorrer toda a arvore em busca da struct referente ao nome da pessoa passada como parametro
        else{
            for (int i = 0; i < pessoaAsc->numFilhos; i++) {
                struct Pessoa *p = buscaPessoa(&pessoaAsc->filho[i], nomeProcurado, nivel, imprimeNivel);
                if(p!=NULL)
                    return p;
            }
        }
    }

    //SEGUNDA FUNCIONALIDADE DA QUINTA PARTE
    if (imprimeNivel == 1){
        //Caso base agora sera printar o nivel de parentesco entre as pessoas passadas como parametro
        if(strcmp(pessoaAsc->nome,nomeProcurado)==0){
            printf("%d\n", nivel);
        }
        else{
            //toda vez que o contador "j" for 0, quer dizer que aumentamos um nivel de parentesco
            for (int i = 0; i < pessoaAsc->numFilhos; i++) {
                if (i == 0){
                    nivel++;
                }
                //o nivel atual deve ser passado como parametro para a funcao recursiva, para a contagem ser feita corretamente
                struct Pessoa *p = buscaPessoa(&pessoaAsc->filho[i], nomeProcurado, nivel, 1);
            }
        }
    }
    return NULL;

};

void liberarMemoria(struct Pessoa *pessoaAsc){
    //a estrutura de repeticao a seguir percorre todos os galhos da arvore genealogica de baixo para cima
    for (int i = 0; i <pessoaAsc->numFilhos; i++) {
        liberarMemoria(&pessoaAsc->filho[i]);
    }
    //Se a pessoa tiver filhos, seu vetor "filho" sera liberado da memoria
    if(pessoaAsc->numFilhos!=0){
        free(pessoaAsc->filho);
    }
};
