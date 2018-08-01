#include <stdio.h>
#include <stdlib.h>

#define TAM_PRINC 10

struct auxiliar {
	int *vet_aux;
};




int  menu (int operador);
void asteriscos ();
int inserir_elemento ();

int main(void) {
	struct auxiliar principal [TAM_PRINC];
	int op;
	
	int pos;
	
	
	op = menu (op);
	
	
	switch (op) {
		case 1: {
			printf ("Informe a posicao da estrutura principal sera alocada: ");
			scanf ("%d", &pos);
			
			
			break;
		}
		
		case 2: {
			
			break;
		}
		
		case 3: {
			
			break;
		}
		
		case 4: {
			
			break;
		}
		
		case 5: {
			
			break;
		}
		
		case 6: {
			
			break;
		}
		
		case 7: {
			
			break;
		}
	}
	
}

int  menu (int operador){
	asteriscos (); printf ("MENU"); asteriscos (); printf ("\n");
	printf ("Inserir elemento\n");
	printf ("Listar numeros de todas as estruturas\n");
	printf ("Listar os números ordenados para cada estrutura auxiliar\n");
	printf ("Listar todos os números de forma ordenada\n");
	printf ("Excluir um elemento\n");
	printf ("Aumentar o tamanho de uma estrutura auxiliar\n");
	printf ("Sair\n");
	printf ("Digite a operacao desejada:");
	scanf ("%d", &operador);
	
	return operador;
}

void asteriscos (){
	int i;
	
	for (i = 0; i < 5; i++)
		printf ("*");
}
