#include <stdio.h>

int hanoi(int tamanho){

	if(tamanho == 1)
		return 1;


	return 2 * hanoi(tamanho - 1) + 1;
}

int main(int argc, char** argv){

	int N;
	for(int teste = 1; 1; teste++){
		scanf("%d", &N);

		if(N == 0)
			break;

		printf("Teste %d\n", teste);
		printf("%d\n\n", hanoi(N));
	}

	return 0;
}
