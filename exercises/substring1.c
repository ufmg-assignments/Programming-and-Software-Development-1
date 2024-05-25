#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int a=0, aux=0, b;
    char S1[100], S2[100];
    fgets(S1, 100, stdin);
    S1[strlen(S1)] = '\0';
    fgets(S2, 100, stdin);
    int c = strlen(S2);
    char S3[c];
    while( a!=strlen(S1) && aux != 1){
        for(b=0; b!= strlen(S2); b++){
            S3[b] = S1[a+b];
            printf("%s", S3);
        //printf("%s", S3);
        }

        if (strcmp(S2,S3) ==0){
            printf("e substring");
            aux = 1;
        }
        a++;
    }

    if(aux==0){
        printf("Neo e substring");
    }
    return 0;
}
