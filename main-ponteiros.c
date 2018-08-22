#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define TAM_PRINC 10

struct auxiliar {
	int *vet_aux;
	int tam_vetor;
	int topo;
};

typedef struct auxiliar aux;


int  menu (int operador);
void asteriscos ();

void novo_vetor (int *vet, int tam);
void novo_elemento (int *vet, int topo);

int main(void) {
	aux principal [TAM_PRINC];
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
				//fflush(stdin);
				__fpurge (stdin);
			
				if (principal[pos].topo == 0){
					printf("\nVetor auxiliar na posicao %d nao criado\nInforme o tamanho do vetor: ",pos);
					scanf ("%d", &principal[pos].tam_vetor);
					//fflush(stdin);
					__fpurge (stdin);

					novo_vetor (principal[pos].vet_aux, principal[pos].tam_vetor);
					novo_elemento (principal[pos].vet_aux, principal[pos].topo);
					principal[pos].topo += 1;
				}
				
				else if (principal[pos].topo == principal[pos].tam_vetor){
						printf ("\n\nVETOR DA POSICAO %d CHEIO\nGostaria de aumentar o valor do vetor auxiliar na posicao %d ?", pos, pos);
				}
				
				break;
			}
		
		}
	} while (op != 7);
	
}


void novo_vetor (int *vet, int tam){
	vet = (int *) malloc (tam * sizeof (int));
}

void novo_elemento (int *vet, int topo){
	
	
	printf ("\n\nDigite o elemento a ser inserido: ");
	scanf ("%d", &vet[topo]);
	//fflush(stdin);
	__fpurge (stdin);
	
}



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
	//fflush(stdin);
	__fpurge (stdin);
	
	return operador;
}

void asteriscos (){
	int i;
	
	for (i = 0; i < 6; i++)
		printf ("*");
}
