//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No{
	
	int valor;
	struct No* prox;
	
} TNo;

typedef TNo* TLista;

//protótipo das funções

void exibir (TLista L);
int inserir (TLista* L, int numero);
int remover (TLista *L, int numero);
int removerPos (TLista *L, int numero);
int alterar (TLista *L, int numero, int novoNumero);
TLista buscar (TLista L, int numero);

//main

void main (){
	
	//declaração de variáveis
	TLista L1 = NULL;
	int opcao, numero, novoNumero;
	
	//while para apresentar as opções para o usuário escolher
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

			//removendo determinado numero em dada posição
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
			//buscando um número e retornando seu índice
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
			
			//caso o usuário digite uma opção inválida
			default: printf("Digite uma opcao valida.\n\n");
			
		}
		
	system ("pause");
	
	}while(opcao != 7);
		
}

//implementação das funções

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
	
	//declaração de variáveis
	TLista aux;
	
	//testando se a lista está vazia
	if (L == NULL){
		
		printf ("\nLista Vazia!\n\n");
		
	}
	
	else{
		
		printf ("\nLista: ");
		
		//inicializando 'aux' de forma que aponte para o primeiro nó da lista
		aux = L;
		
		//percorrendo todos os nós da lista
		while (aux != NULL){
			
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//andar com o 'aux' de forma que ele aponte para o próximo nó
			aux = aux->prox;
			
		}
		
		printf ("\n\n");
		
	}
	
}

int inserir (TLista *L, int numero){
	
	//declaração de variáveis
	TLista aux;
	
	//alocar memória para o novo elemento
	aux = (TLista) malloc (sizeof(TNo));

	//verificando se a memória solicitada não foi alocada
	if (aux == NULL){
		
		return 0;
		
	}
	
	else{
		
		//armazenar o novo valor na memória recém alocada
		aux->valor = numero;
		
		//fazer o novo nó apontar para o nó que, até então, era o primeiro da lista.
		aux->prox = *L;
		//fazer com que o L aponte para o novo elemento
		*L = aux;
		
		return 1;
		
	}
		
}

int remover (TLista *L, int numero){
	
	//declaração de variáveis
	TLista aux1, aux2;
	
	//removendo ocorrências de 'numero' no início da lista
	while ((*L != NULL) && ((*L)->valor == numero)){
		
		//fazer um auxiliar apontar para o primeiro nó
		aux1 = *L;
		
		//fazer 'L' apontar para o "2º" elemento
		*L = aux1->prox;   //ou *L = (*L)->prox;
		
		//liberar a memória apontada por 'aux1'
		free (aux1);
		
		return 1;
		
	}
	
	//verificando se ainda existem elementos na lista
	if (*L != NULL){
		//buscar com 'aux1' o elemento a ser removido e garantir que 'aux2' apontará sempre para o nó anterior ao apontado por 'aux1'
		
		//inicializando os ponteiros 'aux1' e 'aux2'
		aux2 = *L;
		aux1 = aux2->prox;
		
		//percorrendo toda a lista com 'aux1'
		while (aux1 != NULL){
			
			//verificando se o elemento a ser removido foi encontrado
			if (aux1->valor == numero){
				
				//fazer o 'prox' de 'aux2' apontar para o 'prox' do 'aux1'
				aux2->prox = aux1->prox;
				
				//liberar a memória apontada por 'aux1'
				free (aux1);
				
				//fazer com que 'aux1' aponte para o próximo elemento da lista (aquele que era pontado pelo nó que acabou de ser removido)
				aux1 = aux2->prox;
				
				return 1;
				
			} else {
				
				//andando com os auxiliares para os próximos nós
				aux2 = aux1;
				aux1 = aux1->prox;
				
			}
			
		}
		
	}

	return 0;
}

int removerPos (TLista *L, int numero){
	
	//declaração de variáveis
	TLista aux1, aux2;
	int cont = 1;
	
	//removendo ocorrências no início da lista
	while ((*L != NULL) && (cont == numero)){
		
		//fazer um auxiliar apontar para o primeiro nó
		aux1 = *L;
		
		//fazer 'L' apontar para o "2º" elemento
		*L = aux1->prox;
		
		//liberar a memória apontada por 'aux1'
		free (aux1);
		
		return 1;
		
	}
	
	//verificando se ainda existem elementos na lista
	if (*L != NULL){
		//buscar com 'aux1' o elemento a ser removido e garantir que 'aux2' apontará sempre para o nó anterior ao apontado por 'aux1'
		
		//inicializando os ponteiros 'aux1' e 'aux2'
		aux2 = *L;
		aux1 = aux2->prox;
		
		//percorrendo toda a lista com 'aux1'
		while (aux1 != NULL){
			
			//verificando se o elemento a ser removido foi encontrado
			if (cont == numero-1){
				
				//fazer o 'prox' de 'aux2' apontar para o 'prox' do 'aux1'
				aux2->prox = aux1->prox;
				
				//liberar a memória apontada por 'aux1'
				free (aux1);
				
				//fazer com que 'aux1' aponte para o próximo elemento da lista (aquele que era pontado pelo nó que acabou de ser removido)
				aux1 = aux2->prox;
				
				return 1;
				
			} else {
				
				//andando com os auxiliares para os próximos nós
				aux2 = aux1;
				aux1 = aux1->prox;
				cont++;
				
			}
			
		}
		
	}

	return 0;
	
}

int alterar (TLista *L, int numero, int novoNumero){
	
	//declaração de variáveis
	TLista aux;
	
	//inicializando 'aux' de forma que aponte para o primeiro nó da lista
	aux = *L;
	
	while (aux != NULL){
		
		if (aux->valor == numero){
	
			//armazenar o novo valor na memória
			aux->valor = novoNumero;
				
			return 1;
		}
		
		//andar com o 'aux' de forma que ele aponte para o próximo nó
		aux = aux->prox;
		
	}
	
	return 0;
	
}

TLista buscar (TLista L, int numero){
	
	//declaração de variáveis
	TLista aux;
	
	//inicializando 'aux' de forma que aponte para o primeiro nó da lista
	aux = L;
		
	//percorrendo todos os nós da lista
	while (aux != NULL){
		
		//verificando se 'numero' foi encontrado
		if (aux->valor == numero){
			
			return aux;
			
		}
				
		//andar com o 'aux' de forma que ele aponte para o próximo nó
		aux = aux->prox;

	}		
	
	//'numero' não existe na lista
	return NULL;
}
