//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de tipos
typedef struct No{
	
	int valor;
	struct No* prox;
	
} TNo;

typedef TNo* TLista;

//prot�tipo das fun��es

void exibir (TLista L);
int inserir (TLista* L, int numero);
int remover (TLista *L, int numero);
int removerPos (TLista *L, int numero);
int alterar (TLista *L, int numero, int novoNumero);
TLista buscar (TLista L, int numero);

//main

void main (){
	
	//declara��o de vari�veis
	TLista L1 = NULL;
	int opcao, numero, novoNumero;
	
	//while para apresentar as op��es para o usu�rio escolher
	do{
		
		opcao = menu ();
	
		switch (opcao){
			
			//inserindo novo numero
			case 1: printf ("\nDigite o elemento que deseja inserir: ");
					scanf ("%d" , &numero);
					
					if (buscar(L1, numero) != NULL){
						
						printf("\nO numero ja existe na lista!\n\n");
						
						
					} else {
						
						inserir (&L1, numero);
						printf ("\nNumero inserido com sucesso!\n\n");
						
					}
					
					break;
					
			//removendo determinado numero		
			case 2: exibir (L1);
			
					printf ("Digite o valor que deseja remover: ");
					scanf ("%d" , &numero);
					
					if (remover (&L1, numero) == 0){

						printf("\nO numero nao existe na lista!\n\n");
						
					} else {
						
						printf("\nNumero removido com sucesso.\n\n");
						
					}
					
					break;

			//removendo determinado numero em dada posi��o
			case 3: exibir (L1);
			
					printf ("Digite a posicao que deseja remover: ");
					scanf ("%d" , &numero);
					
					if (removerPos (&L1, numero) == 0){
						
						printf ("\nPosicao invalida!\n\n");
						
					} else {
						
						printf ("\nO numero presente em determinada posicao foi removido com sucesso.\n\n");
					}
					
					break;
					
			//alterando um numero
			case 4: exibir (L1);
	
					printf ("Digite o numero que deseja alterar: ");
					scanf ("%d" , &numero);
					
					printf ("\nDigite o novo numero: ");
					scanf ("%d" , &novoNumero);
					
					if (buscar(L1, novoNumero) != NULL){
						
						printf("\nO numero ja existe na lista!\n\n");
						
					} else {
						
						if (alterar (&L1, numero, novoNumero) == 0){
							
							printf("\nO numero nao existe na lista!\n\n");
							
						} else {
							
							printf ("\nNumero alterado com sucesso!\n\n");
							
						}
						
						
					}
					
					break;
			//buscando um n�mero e retornando seu �ndice
			case 5: exibir (L1);
			
					printf ("Digite o numero que deseja buscar: ");
					scanf ("%d" , &numero);
					
					if (buscar (L1, numero) == NULL){
						
						printf("\nO numero nao existe na lista: %p\n\n" , buscar(L1, numero));
						
					} else {
						
						printf("\nO numero encontra-se na posicao: %p\n\n" , buscar(L1, numero));
					}
					
					break;
			
			//exibindo a lista
			case 6: exibir (L1);
			
			        break;
			
			//finalizando programa
			case 7: printf ("\nFim do programa.\n\n");
			
				    break;
			
			//caso o usu�rio digite uma op��o inv�lida
			default: printf("Digite uma opcao valida.\n\n");
			
		}
		
	system ("pause");
	
	}while(opcao != 7);
		
}

//implementa��o das fun��es

int menu (){
	
	int op;
	
	system ("cls");
	
	printf ("Menu:\n\n");
	
	printf ("1 - Inserir um novo numero;\n");
	printf ("2 - Remover um determinado numero;\n");
	printf ("3 - Remover um numero em determinada posicao\n");
	printf ("4 - Alterar um numero;\n");
	printf ("5 - Buscar um determinado numero;\n");
	printf ("6 - Exibir lista;\n");
	printf ("7 - Encerrar programa.\n\n");
	
	scanf ("%d", &op);
	
	return op;
}

void exibir (TLista L){
	
	//declara��o de vari�veis
	TLista aux;
	
	//testando se a lista est� vazia
	if (L == NULL){
		
		printf ("\nLista Vazia!\n\n");
		
	}
	
	else{
		
		printf ("\nLista: ");
		
		//inicializando 'aux' de forma que aponte para o primeiro n� da lista
		aux = L;
		
		//percorrendo todos os n�s da lista
		while (aux != NULL){
			
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//andar com o 'aux' de forma que ele aponte para o pr�ximo n�
			aux = aux->prox;
			
		}
		
		printf ("\n\n");
		
	}
	
}

int inserir (TLista *L, int numero){
	
	//declara��o de vari�veis
	TLista aux;
	
	//alocar mem�ria para o novo elemento
	aux = (TLista) malloc (sizeof(TNo));

	//verificando se a mem�ria solicitada n�o foi alocada
	if (aux == NULL){
		
		return 0;
		
	}
	
	else{
		
		//armazenar o novo valor na mem�ria rec�m alocada
		aux->valor = numero;
		
		//fazer o novo n� apontar para o n� que, at� ent�o, era o primeiro da lista.
		aux->prox = *L;
		//fazer com que o L aponte para o novo elemento
		*L = aux;
		
		return 1;
		
	}
		
}

int remover (TLista *L, int numero){
	
	//declara��o de vari�veis
	TLista aux1, aux2;
	
	//removendo ocorr�ncias de 'numero' no in�cio da lista
	while ((*L != NULL) && ((*L)->valor == numero)){
		
		//fazer um auxiliar apontar para o primeiro n�
		aux1 = *L;
		
		//fazer 'L' apontar para o "2�" elemento
		*L = aux1->prox;   //ou *L = (*L)->prox;
		
		//liberar a mem�ria apontada por 'aux1'
		free (aux1);
		
		return 1;
		
	}
	
	//verificando se ainda existem elementos na lista
	if (*L != NULL){
		//buscar com 'aux1' o elemento a ser removido e garantir que 'aux2' apontar� sempre para o n� anterior ao apontado por 'aux1'
		
		//inicializando os ponteiros 'aux1' e 'aux2'
		aux2 = *L;
		aux1 = aux2->prox;
		
		//percorrendo toda a lista com 'aux1'
		while (aux1 != NULL){
			
			//verificando se o elemento a ser removido foi encontrado
			if (aux1->valor == numero){
				
				//fazer o 'prox' de 'aux2' apontar para o 'prox' do 'aux1'
				aux2->prox = aux1->prox;
				
				//liberar a mem�ria apontada por 'aux1'
				free (aux1);
				
				//fazer com que 'aux1' aponte para o pr�ximo elemento da lista (aquele que era pontado pelo n� que acabou de ser removido)
				aux1 = aux2->prox;
				
				return 1;
				
			} else {
				
				//andando com os auxiliares para os pr�ximos n�s
				aux2 = aux1;
				aux1 = aux1->prox;
				
			}
			
		}
		
	}

	return 0;
}

int removerPos (TLista *L, int numero){
	
	//declara��o de vari�veis
	TLista aux1, aux2;
	int cont = 1;
	
	//removendo ocorr�ncias no in�cio da lista
	while ((*L != NULL) && (cont == numero)){
		
		//fazer um auxiliar apontar para o primeiro n�
		aux1 = *L;
		
		//fazer 'L' apontar para o "2�" elemento
		*L = aux1->prox;
		
		//liberar a mem�ria apontada por 'aux1'
		free (aux1);
		
		return 1;
		
	}
	
	//verificando se ainda existem elementos na lista
	if (*L != NULL){
		//buscar com 'aux1' o elemento a ser removido e garantir que 'aux2' apontar� sempre para o n� anterior ao apontado por 'aux1'
		
		//inicializando os ponteiros 'aux1' e 'aux2'
		aux2 = *L;
		aux1 = aux2->prox;
		
		//percorrendo toda a lista com 'aux1'
		while (aux1 != NULL){
			
			//verificando se o elemento a ser removido foi encontrado
			if (cont == numero-1){
				
				//fazer o 'prox' de 'aux2' apontar para o 'prox' do 'aux1'
				aux2->prox = aux1->prox;
				
				//liberar a mem�ria apontada por 'aux1'
				free (aux1);
				
				//fazer com que 'aux1' aponte para o pr�ximo elemento da lista (aquele que era pontado pelo n� que acabou de ser removido)
				aux1 = aux2->prox;
				
				return 1;
				
			} else {
				
				//andando com os auxiliares para os pr�ximos n�s
				aux2 = aux1;
				aux1 = aux1->prox;
				cont++;
				
			}
			
		}
		
	}

	return 0;
	
}

int alterar (TLista *L, int numero, int novoNumero){
	
	//declara��o de vari�veis
	TLista aux;
	
	//inicializando 'aux' de forma que aponte para o primeiro n� da lista
	aux = *L;
	
	while (aux != NULL){
		
		if (aux->valor == numero){
	
			//armazenar o novo valor na mem�ria
			aux->valor = novoNumero;
				
			return 1;
		}
		
		//andar com o 'aux' de forma que ele aponte para o pr�ximo n�
		aux = aux->prox;
		
	}
	
	return 0;
	
}

TLista buscar (TLista L, int numero){
	
	//declara��o de vari�veis
	TLista aux;
	
	//inicializando 'aux' de forma que aponte para o primeiro n� da lista
	aux = L;
		
	//percorrendo todos os n�s da lista
	while (aux != NULL){
		
		//verificando se 'numero' foi encontrado
		if (aux->valor == numero){
			
			return aux;
			
		}
				
		//andar com o 'aux' de forma que ele aponte para o pr�ximo n�
		aux = aux->prox;

	}		
	
	//'numero' n�o existe na lista
	return NULL;
}
