#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int jogos, jogadas, j, tam, lin, col, x, y, res, a, b, c, d, cnt, aux, pr1, pr2;
    char valor;
    // numero de vezes que o usuário que jogar (deve ser pelo menos uma e no maximo dez vezes):
    do{
        scanf("%d", &jogos);
    } while (jogos <1 || jogos >10);
    // o for a seguir executa o jogo quantas vezes o usuário especificou
    for(j = 0; j!= jogos; j++){
        // primeiro identificamos qual sera o tamanho do campo minado e criamos uma matriz do tipo char:
        do{
            scanf("%d", &tam);
        }while (tam<2 || tam >100);
        char Campo[tam][tam];
        // em seguida, o usuário preeche o campo com bombas (b) ou (x)
        for(lin=0; lin!=tam; lin++){
            for(col=0; col!=tam; col++){
                do{
                    valor = getchar();
                    Campo[lin][col] = valor;
                }while (valor!= 'b' && valor!='x');
            }
        }
        // O usuario deve entrar com o numero de jogadas que podera realizar
        scanf("%d", &jogadas);
        res = 0;
        while (jogadas != 0){
            // Verificacao se a entrada do usuario esta definida no campo
            do{
                scanf("%d %d", &x, &y);
            } while((x<0 || x >tam) && (y<0 || y>tam));
            // Se o usuario escolher uma bomba (b) ele perde
            if (Campo[x][y] == 'b'){
                res = 1;
            }
            else{
                Campo[x][y] = 'v';
                if (x==0){
                    if(y ==0){
                        a =0;
                        b =1;
                        c =0;
                        d =1;
                        aux =4;
                    }
                    else if (y==tam-1){
                        a =-1;
                        b =0;
                        c =0;
                        d =1;
                        aux =4;
                    }
                    else{
                        a =-1;
                        b =1;
                        c =0;
                        d =1;
                        aux =6;
                    }
                }
                else if (x==tam-1){
                    if (y==0){
                        a =0;
                        b =1;
                        c =-1;
                        d =0;
                        aux =4;
                    }
                    else if (y == tam-1){
                        a =-1;
                        b =0;
                        c =-1;
                        d =0;
                        aux =4;
                    }
                    else{
                        a =-1;
                        b =1;
                        c =-1;
                        d =0;
                        aux =6;
                    }
                }
                else if (y==0 && x!= 0 && x!=tam-1){
                    a =0;
                    b =1;
                    c =-1;
                    d =1;
                    aux =6;
                }
                else if (y==tam-1 && x!=0 && x!=tam-1){
                    a =-1;
                    b =0;
                    c =-1;
                    d =1;
                    aux =6;
                }
                else{
                    a =-1;
                    b =1;
                    c =-1;
                    d =1;
                    aux =9;
                }
                cnt = 0;
                for(pr1 = a; pr1<=b; pr1++ ){
                    for(pr2 = c; pr2<=d; pr2++ ){
                        if (Campo[x+pr2][y+pr1] != 'b'){
                            cnt++;
                        }
                    }
                }
                if(cnt == aux){
                    for(pr1 = a; pr1<=b; pr1++ ){
                        for(pr2 = c ; pr2<=d; pr2++ ){
                            Campo[x+pr2][y+pr1] = 'v';
                        }
                    }
                }
                }
            jogadas--;
        }
        //Verificacao se o usuario ganhou ou se nao terminou o jogo, caso nao tenha clicado em uma bomba
        if (res==1){
            printf("PERDEU\n");
        }
        else if (res ==0){
            for(lin=0; lin!=tam; lin++){
                if(res == 1){
                    break;
                }
                for(col=0; col!=tam; col++){
                    if(Campo[lin][col] == 'x'){
                        printf("FALTOU TERMINAR\n");
                        res = 1;
                        break;
                    }
                }
            }
        }
        if(res == 0){
            printf("GANHOU\n");
        }
    }
    return 0;
}
