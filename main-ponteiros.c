#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> 

#define TAM_PRINC 10

struct auxiliar {
	int *vet_aux;
	int tam_vetor;
	int topo;
};




int  menu (int operador);
void asteriscos ();
//void inserir_elemento (struct auxiliar *elemento);

int main(void) {
	struct auxiliar principal [TAM_PRINC];
	int op;
	int i;
	int pos;
	
	for (i = 0; i < TAM_PRINC; i++)
		principal[i].topo = 0;

	do {
	op = menu (op);
		
	switch (op) {
		case 1: {
				printf ("Informe a posicao da estrutura principal sera alocada: ");
				scanf ("%d", &pos);
				__fpurge(stdin);
			
				if (principal[pos].topo == 0){
					printf("\nVetor auxiliar na posicao %d nao criado\nInforme o tamanho do vetor: ",pos);
					scanf ("%d", &principal[pos].tam_vetor);
					__fpurge(stdin);
				}

				principal[pos].vet_aux = (int *) malloc (sizeof (struct auxiliar));

				//inserir_elemento (principal[pos].vet_aux);
				break;
			}
		
		}
	} while (op != 7);
	
}

/*
void inserir_elemento (struct auxiliar *elemento){
	int x;
	printf("Digite o elemento\n");
	scanf ("%d", &x);


}
*/






int  menu (int operador){
	asteriscos (); printf ("MENU"); asteriscos (); printf ("\n");
	printf ("1 - Inserir elemento\n");
	printf ("2 - Listar numeros de todas as estruturas\n");
	printf ("3 - Listar os números ordenados para cada estrutura auxiliar\n");
	printf ("4 - Listar todos os números de forma ordenada\n");
	printf ("5 - Excluir um elemento\n");
	printf ("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
	printf ("7 - Sair\n");
	printf ("Digite a operacao desejada:");
	scanf ("%d", &operador);
	
	return operador;
}

void asteriscos (){
	int i;
	
	for (i = 0; i < 6; i++)
		printf ("*");
}
