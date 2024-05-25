#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char S1[100], S2[100];
    gets(S1);
    gets(S2);
    int i, cont, k =0;
    for (i=0; i< strlen(S1); i++){
        if (S1[i] == S2[k]){
            cont++;
            k++;}
        else{
            cont=0;
            k =0;
            if(S1[i] == S2[k]){
                k++;
                cont++;}}
        if(cont == strlen(S2)){
            printf("eh substring");
            break;}}
    if(cont != strlen(S2)){
        printf("Nao e substring");
    }
    return 0;
}
