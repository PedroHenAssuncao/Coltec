/**
* @file		Hash.c
* @brief	Arquivo com as implementa��es de Hash.
* @author	Pedro Henrique Assun��o
* @date		2020-11-05
*/

/* Inclus�es */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "Erros.h"
#include "Tipos.h"
#include "Structs.h"
#include "Perfil.h"
#include "ListaE.h"

// INICIO - manipula��o de Hash

/**
* Fun��o que cria e inicializa uma nova tabela
* @param  void
* @return Endere�o da nova Tabela caso tudo de certo, caso contr�rio retornar� NULL
*/
HashTable* CriaTabela(void) {

	// Aloca um espa�o na mem�ria para a struct da nova tabela
	HashTable * novaTabela = (HashTable*)malloc(sizeof(HashTable));

	// Caso a aloca��o falhe retornar� NULL
	if (novaTabela == NULL) return NULL;

	// Inicializa o n�mero de colunas como 0
	novaTabela->nColunas = 0;
	// Aloca espa�o vara o vetor de ponteiros que seria a tabela propriamente dita
	novaTabela->DadosTabela = (Item_lista**)malloc(sizeof(Item_lista*));

	// Inicializa com valor NULL
	novaTabela->DadosTabela = NULL;

	// Se cheogu at� aqui � porque tudo correu bem
	return novaTabela;
}

/**
* Fun��o que ao receber uma string retorna a coluna onde o item ser� inserido na tabela
  em outras palavras � a fun��o que cria uma chave
* @param  Char apontador para uma string
* @return Inteiro que cont�m o n�mero da coluna na qual essa string seria inserida
*/
unsigned int IdentificaColuna(char * string){
	
	unsigned int i;
	unsigned int coluna = 0;

	// Percorre a string somando todos os caracteres
	for (i = 0; i < strlen(string); i++) {
		coluna += (int)string[i];
	}

	// Retorna a soma de todos os caracteres da string divido por 10
	return (coluna / 10);
}


/**
* Fun��o que insere um novo item na tabela
* @param  HashTable apontador para a tabela onde ser� inserido o novo item
* @param  DataType apontador para os dados que ser�o colocados nesse novo item
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t InsereTabela(HashTable * table, TipoDado * DadosItem){

	// Verifica se os par�metros s�o v�lidos
	if ((table == NULL) || (DadosItem == NULL)) return ERRO_ARGUMENTO_INVALIDO;

	unsigned int nColuna = IdentificaColuna(DadosItem->Nome);
	unsigned int i;
	Item_lista** novaTabela = NULL;
	Item_lista* Aux;

	// Aloca espa�o para um novo item
	Item_lista* novoItem = (Item_lista*)malloc(sizeof(Item_lista));
	// Testa se a aloca��o funcionou
	if (novoItem == NULL) return ERRO_ALOCACAO_MEMORIA;

	novoItem->DadosItem = DadosItem;
	novoItem->Proximo = NULL;
	novoItem->DadosItem->ID = DadosItem->ID;

	if (nColuna > table->nColunas){

		novaTabela = (Item_lista**)realloc(table->DadosTabela, sizeof(Item_lista*) * nColuna);

		if (novaTabela == NULL) { 
			
			free(novoItem);
			return ERRO_ALOCACAO_MEMORIA;
		}

		for (i = table->nColunas; i < nColuna; i++){
			novaTabela[i] = NULL;
		}

		table->DadosTabela = novaTabela;
		table->nColunas = nColuna;
	}
	
	if (table->DadosTabela[nColuna-1] == NULL){
		table->DadosTabela[nColuna - 1] = novoItem;
	}

	else {
		Aux = table->DadosTabela[nColuna - 1];
		while (Aux->Proximo != NULL){

			Aux = Aux->Proximo;
		}

		Aux->Proximo = novoItem;
		novoItem->Anterior = Aux;
	}

	return SUCESSO;
	
}

/**
* Fun��o para a remo��o de um item da tabela
* @param HashTable apontador para a tabela que ter� um item removido
* @param Vetor Char que cont�m o nome de quem ser� removido
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t RemoveTabela(HashTable * table, char nome [TAMANHO_MAXIMO_STRING]) {

	unsigned int Coluna = (IdentificaColuna(nome) - 1);
	Item_lista* atual = NULL, * proximo = NULL, *aux, *aux2;
	unsigned int i,j;

	if (table->DadosTabela[Coluna] == NULL) return ERRO_DADO_NAO_ENCONTRADO;

	proximo = table->DadosTabela[Coluna];

	for (j = 0; j < table->nColunas; j++) {

		if (proximo != NULL) {
			if (strcmp(nome, proximo->DadosItem->Nome) == 0) {
				if (atual == NULL) {

					table->DadosTabela[Coluna] = proximo->Proximo;
					LiberaListaAdjacencia(proximo->DadosItem->Seguindo);
					for (i = 0; i < table->nColunas; i++) {

						aux = table->DadosTabela[i];

						if (aux != NULL) {

							while (aux != NULL) {

								aux2 = aux;
								aux = aux2->Proximo;
								RemoveListaAresta(aux2->DadosItem->Seguindo, proximo->DadosItem);

							}
						}
					}
					free(proximo->DadosItem);
					free(proximo);

				}

				else if (proximo->Proximo == NULL) {

					atual->Proximo = proximo->Proximo;
					LiberaListaAdjacencia(proximo->DadosItem->Seguindo);
					for (i = 0; i < table->nColunas; i++) {

						aux = table->DadosTabela[i];

						if (aux != NULL) {

							while (aux != NULL) {

								aux2 = aux;
								aux = aux2->Proximo;
								RemoveListaAresta(aux2->DadosItem->Seguindo, proximo->DadosItem);

							}
						}
					}
					free(proximo->DadosItem);
					free(proximo);
				}
				else {
					atual->Proximo = proximo->Proximo;
					proximo->Proximo->Anterior = atual;
					LiberaListaAdjacencia(proximo->DadosItem->Seguindo);
					for (i = 0; i < table->nColunas; i++) {

						aux = table->DadosTabela[i];

						if (aux != NULL) {

							while (aux != NULL) {

								aux2 = aux;
								aux = aux2->Proximo;
								RemoveListaAresta(aux2->DadosItem->Seguindo, proximo->DadosItem);

							}
						}
					}
					free(proximo->DadosItem);
					free(proximo);

				}

				break;
			}
		}

		atual = proximo;
		proximo = atual->Proximo;
	}

	return SUCESSO;
}

/**
* Fun��o que remove um perfil da tabela de curtidas
* @param HashTable apontador para a tabela de curtidas
* @param char que cont�m o nome o nome do perfil que ser� inserido na tabela
* @return SUCESSO caso de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t RemoveTabelaCurtidas(HashTable* table, char nome[TAMANHO_MAXIMO_STRING]) {

	unsigned int Coluna = (IdentificaColuna(nome) - 1);
	Item_lista* atual = NULL, * proximo = NULL;

	if (table->nColunas < Coluna) return ERRO_DADO_NAO_ENCONTRADO;

	if (table->DadosTabela[Coluna] == NULL) return ERRO_DADO_NAO_ENCONTRADO;

	proximo = table->DadosTabela[Coluna];

	while (proximo != NULL) {
		if (strcmp(nome, proximo->DadosItem->Nome) == 0) {
			if (atual == NULL) {

				table->DadosTabela[Coluna] = proximo->Proximo;

			}
			else {
				atual->Proximo = proximo->Proximo;
				proximo->Proximo->Anterior = atual;

			}

			break;
		}

		atual = proximo;
		proximo = atual->Proximo;
	}

	return SUCESSO;
}

/**
* Fun��o para a impress�o de uma coluna da tabela
* @param HashTable apontador para a tabela que ter� uma coluna impressa
* @param Unsigned Int que cont�m o n�mero da coluna que ser� impressa
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t ImprimeColuna(HashTable* table, unsigned int Coluna) {

	TipoDado* imprime = NULL;
	Item_lista* aux = NULL;

	aux = table->DadosTabela[Coluna];

	if (aux == NULL) return ERRO_DADO_NAO_ENCONTRADO;

	while (aux != NULL){

		imprime = aux->DadosItem;
		printf("\nNome: %-30s   ID: %d\n", imprime->Nome, imprime->ID);
		printf("Email: %-30s\n", imprime->Email);
		aux = aux->Proximo;
	}

	return SUCESSO;
}

/**
* Fun��o que imprime toda a tabela
* @param HashTable apontador para a tabela que ser� imprimida
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t ImprimeTable(HashTable* table) {

	unsigned int i;

	if (table == NULL) return ERRO_ARGUMENTO_INVALIDO;

	if (table->DadosTabela == NULL) return ERRO_TABELA_VAZIA;

	printf("\n\t Imprimindo perfis\n\n");
	for ( i = 0; i < table->nColunas; i++){

		ImprimeColuna(table, i);
	}

	printf("\n");

	return SUCESSO;
}

/**
* Fun��o para a libera��o da mem�ria usada pela tabela
* @param HashTable apontador para a tabela a ser liberada
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t LiberaTabela(HashTable * table){
	
	if (table == NULL) return ERRO_ARGUMENTO_INVALIDO;

	unsigned int i;
	Item_lista* atual = NULL, *proximo = NULL;

	for (i = 0; i < table->nColunas; i++) {
		
		proximo = table->DadosTabela[i];

		if (proximo != NULL){

			while (proximo != NULL){

				atual = proximo;
				proximo = atual->Proximo;

				LiberaListaAdjacencia(atual->DadosItem->Seguindo);
				LiberaListaPostagens(atual->DadosItem->postagens);
				
				free(atual->DadosItem);
				free(atual);
			}
		}
	}

	free(table->DadosTabela);
	table->nColunas = 0;
	table->DadosTabela = (Item_lista**)malloc(sizeof(Item_lista*));

	if (table->DadosTabela == NULL) return ERRO_ALOCACAO_MEMORIA;

	return SUCESSO;
}