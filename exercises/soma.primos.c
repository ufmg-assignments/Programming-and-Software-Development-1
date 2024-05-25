#include <stdio.h>
#include <stdlib.h>

int Primo(int a){
    unsigned long long int con=0, c;
    int res;
    for(c=1; c<=a/2; c++){
        if(a%c == 0)
            con++;
    }
    if(con == 1){
        res = 1;
    }
    else{
        res = 0;
    }

    return res;
}


int Soma_Primos(int num){
    int aux=0;
    unsigned long long int soma=0, k=2;
    while(aux!=num){
        if(Primo(k)==1){
            aux++;
            soma+=k;
        }
        k++;
    }
    return soma;

}

int main(){
    unsigned long long int n;
    scanf("%llu", &n);
    do{
        printf("%llu\n", Soma_Primos(n));
    }while(scanf("%llu", &n) != EOF);
    return 0;
}
