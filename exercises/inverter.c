#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char S1[100], C1, C2;
    fgets(S1, 100, stdin);
    scanf("%c\n%c", &C1, &C2);
    int n = strlen(S1), c;
    for (c=0; c!= strlen(S1); c++){
        if(S1[c] == C1){
            S1[c] = C2;
            break;
        }

    }
    printf("%s", S1);
    return 0;
}
