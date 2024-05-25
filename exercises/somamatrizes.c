#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){

    long int A[50], S [5][5];
    char arquivo[100];
    int cnt =0, num=0, a, b;
    gets(arquivo);
    FILE *arq;
    arq = fopen(arquivo, "rb");

    cnt=0;
    fscanf(arq,"%d",&num);
    do{
        A[cnt] = num;
        cnt++;
    }while(fscanf(arq,"%d",&num)!= EOF);
    fclose(arq);

    for(a=0;a!=25;a++){
        printf("%d ", A[a]+A[25+a]);
        if ((a+1)%5==0){
            printf("\n");
        }
    }

    return 0;
}

