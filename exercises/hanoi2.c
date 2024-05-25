#include <stdio.h>

int main(int argc, char** argv){

	int N;
	for(int teste = 1; 1; teste++){
		scanf("%d", &N);

		if(N == 0)
			break;

		printf("Teste %d\n", teste);
		printf("%d\n\n", (1 << N) - 1);
	}

	return 0;
}
