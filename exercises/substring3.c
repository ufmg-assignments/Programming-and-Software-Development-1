#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int a, b, aux;
    char S1[100], S2[100];
    gets(S1);
    gets(S2);
    char S3[strlen(S2)];
    for(a=0; a!= strlen(S1)-strlen(S2)+1; a++){
        for(b=0; b!= strlen(S2)-1; b++){
            S3[b] = S1[a+b];
        S3[strlen(S2)-1] = '\0';
        printf("%s\n", S3);
        printf("%s", S2);
        if (strcmp(S2,S3)==0){
            aux = 1;
            break;
        }
        }
    }
    if(aux==0){
        printf("Nao e substring");
    }
    else{
        printf("E string");
    }
    return 0;
}
