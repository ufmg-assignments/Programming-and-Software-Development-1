#include <stdlib.h>
#include <stdio.h>

int main(){
    int lin=0, col=0;
    scanf("%d", &lin);
    scanf("%d", &col);

    int **matriz ;


    matriz = malloc (lin* sizeof (int*)) ;

    int aux=0;
    for (int a=0; a < lin; a++){
        matriz[a] = malloc (col * sizeof (int));
        for (int b=0; b < col; b++){
            scanf("%d", &aux);
            matriz[a][b] = aux;
        }
    }

    for (int a=0; a < lin; a++){
       for (int b=0; b < col; b++){
          printf("%d ", matriz[a][b]);
       }
       printf("\n");
    }

    for (int a=0; a < lin; a++){
       free (matriz[a]);
    }
    free (matriz);
    return 0;
}
