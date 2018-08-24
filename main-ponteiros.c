#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>

#define TAM_PRINC 10

struct auxiliar {
	int *vet_aux;
	int tam_vetor;
	int topo;
};

typedef struct auxiliar aux;


int  menu (int operador);
void asteriscos ();

void novo_vetor (int **vet, int tam);
void novo_elemento (int *vet, int topo);
void lista_todos (int vet[], int tam);
void lista_ordenado (int vet[], int topo);
void insertionSortC(int array[], int tamanho);
void aumentar_vetor (int **vet, int tam);

int main(void) {
	aux principal [TAM_PRINC];
	int op;
	int i;
	int pos;
	int pos_excluir;

	for (i = 0; i < TAM_PRINC; i++)
		principal[i].topo = 0;

    for (i = 0; i < TAM_PRINC; i++)
		principal[i].vet_aux = NULL;

	do {
	op = menu (op);

	switch (op) {
			case 1: {
				//Inserir elemento

				printf ("Informe a posicao da estrutura principal sera alocada: ");
				scanf ("%d", &pos);
				fflush(stdin);
				//__fpurge (stdin);

				if (principal[pos].topo == 0){
					printf("\nVetor auxiliar na posicao %d nao criado\nInforme o tamanho do vetor: ",pos);
					scanf ("%d", &principal[pos].tam_vetor);
					fflush(stdin);
					//__fpurge (stdin);

					novo_vetor (&principal[pos].vet_aux, principal[pos].tam_vetor);

					printf("\nendereco: %p\n" , principal[pos].vet_aux);

					novo_elemento (principal[pos].vet_aux, principal[pos].topo);

					printf("Valor inserido out function: %d\n", principal[pos].vet_aux[principal[pos].topo] );

					principal[pos].topo += 1;
				}

				else if (principal[pos].topo == principal[pos].tam_vetor){
						printf ("\n\nVETOR DA POSICAO %d CHEIO\n", pos);
				}

				else if (principal[pos].topo < principal[pos].tam_vetor && principal[pos].topo > 0){
					novo_elemento (principal[pos].vet_aux, principal[pos].topo);
					principal[pos].topo += 1;
				}
				system ("PAUSE");
				system ("cls");
				break;
			}

			case 2: {
				//Listar numeros de todas as estruturas

				for (i = 0; i < TAM_PRINC; i++){
					printf("VETOR AUXILIAR DA POSICAO %d:", i);
					lista_todos (principal[i].vet_aux, principal[i].topo);
				}
				system ("PAUSE");
				system ("cls");
				break;
			}
			case 3: {
				//Listar os numeros ordenados para cada estrutura auxiliar
				for (i = 0; i < TAM_PRINC; i++){
					printf("VETOR AUXILIAR DA POSICAO %d:", i);
					lista_ordenado (principal[i].vet_aux, principal[i].topo);
					printf ("\n");
				}
				break;
			}
			case 4: {
				//Listar todos os numeros de forma ordenada
				printf ("\n\nFUNCAO AINDA NAO IMPLEMENTADA");
				break;
			}
			case 5: {
				//Excluir um elemento
				
				
				printf ("De qual posicao da estrutura principal voce deseja excluir: ");
				scanf ("%d", &pos_excluir);
				fflush(stdin);
				//__fpurge (stdin);
				
				principal[pos_excluir].topo -= 1;
				break;
			}
			case 6: {
				//Aumentar o tamanho de uma estrutura auxiliar
				
				printf ("Digite a posicao da estrutura principal que quer aumentar: ");
				scanf ("%d", &pos);
				fflush(stdin);
				//__fpurge (stdin);
				
				printf ("Digite o novo tamanho total do vetor: ");
				scanf ("%d", &principal[pos].tam_vetor);
				fflush(stdin);
				//__fpurge (stdin);
				
				aumentar_vetor (&principal[pos].vet_aux, principal[pos].tam_vetor);
				
				break;
			}
		}
	} while (op != 7);

	return 0;

}


void novo_vetor (int **vet, int tam){

	*vet = (int *) malloc (tam * sizeof (int));
}

void novo_elemento (int *vet, int topo){

    printf("\nPonteiro: %p\n", vet);

	printf ("\n\nDigite o elemento a ser inserido: ");

	scanf ("%d", &vet[topo]);

    printf("Valor inserido in function: %d\n", vet[topo]);

	fflush(stdin);
	//__fpurge (stdin);

}

void lista_todos (int vet[], int topo){
	int i;

	for (i = 0; i < topo; i++){
		printf("%d ", vet[i]);
	}

	printf("\n");
}

void lista_ordenado (int *vet, int topo){
	int i;
	int *v = NULL;
	
	v = (int *) malloc (topo * sizeof (int));

	for (i = 0; i < topo; i++){
		v[i] = vet[i];
	}

	insertionSortC (v, topo);

	for (i = 0; i < topo; i++)
		printf ("%d ",v[i]);

	free (v);
}


void insertionSortC(int array[], int tamanho) {
      int i, j, tmp;
      for (i = 1; i < tamanho; i++) {
            j = i;
            while (j > 0 && array[j - 1] > array[j]) {
                  tmp = array[j];
                  array[j] = array[j - 1];
                  array[j - 1] = tmp;
                  j--;
            }
      }
}

void aumentar_vetor (int **vet, int tam){
	*vet = (int *) realloc (vet,  sizeof (int) * tam);
}

int  menu (int operador){
	asteriscos (); printf ("MENU"); asteriscos (); printf ("\n");
	printf ("1 - Inserir elemento\n");
	printf ("2 - Listar numeros de todas as estruturas\n");
	printf ("3 - Listar os numeros ordenados para cada estrutura auxiliar\n");
	printf ("4 - Listar todos os numeros de forma ordenada\n");
	printf ("5 - Excluir um elemento\n");
	printf ("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
	printf ("7 - Sair\n");
	printf ("Digite a operacao desejada:");
	scanf ("%d", &operador);
	fflush(stdin);
	//__fpurge (stdin);
	system ("cls");
	return operador;
}

void asteriscos (){
	int i;

	for (i = 0; i < 6; i++)
		printf ("*");
}
