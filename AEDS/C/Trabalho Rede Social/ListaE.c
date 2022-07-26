/**
* @file		ListaE.c
* @brief	Arquivo com as implementa��es de lista para manipular o grafo.
* @author	Pedro Henrique Assun��o
* @date		2020-11-12
*/


/* Inclus�es */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Erros.h"
#include "Tipos.h"
#include "ListaE.h"
#include "Structs.h"
#include "Hash.h"


// Manipula��es de lista de Arestas - INICIO

/**
* Fun��o que cria e inicializa a lista de arestas/amigos
* @param Lista_Aresta apontador para a lista que ser� inicializada
* @return Endere�o da lista inicializada caso de certo, caso contr�rio retornar� NULL
*/
Lista_Aresta* InicializaListaArestas(Lista_Aresta * lista){
	
	lista = (Lista_Aresta*)malloc(sizeof(Lista_Aresta));

	if (lista == NULL) return NULL;

	lista->Seguidores = 0;
	lista->primeiro = NULL;

	return lista;
}

/**
* Fun��o que insere no inicio da lista de aresta/amigos
* @param Lista_Aresta apontador para a lista que tera um novo membro
* @param Item_lista apontador para quem ser� inserido
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t InsereInicioListaArestas(Lista_Aresta * lista, Item_lista * QuemInserir){
	
	if ((lista == NULL) || (QuemInserir == NULL)) return ERRO_ARGUMENTO_INVALIDO;
	
	Item_lista* novaAresta = (Item_lista*)malloc(sizeof(Item_lista));

	if (novaAresta == NULL) return ERRO_ALOCACAO_MEMORIA;

	novaAresta->Anterior = NULL;
	novaAresta->Proximo = NULL;
	novaAresta->DadosItem = QuemInserir->DadosItem;

	if (lista->primeiro == NULL) {

		novaAresta->Proximo = lista->primeiro;
		lista->primeiro = novaAresta;
	}

	else {

		novaAresta->Proximo = lista->primeiro;
		lista->primeiro->Anterior = novaAresta;
		lista->primeiro = novaAresta;
	}

	lista->Seguidores++;

	return SUCESSO;
}

/**
* Fun��o para remover um item da lista de arestas/amigos
* @param Lista_Aresta apontador para a lista que ser� alterada
* @param TipoDado apontador para o novo item que ser� adicionado
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t RemoveListaAresta(Lista_Aresta * lista, TipoDado * Seguidor){
	
	if ((lista == NULL) || (Seguidor == NULL)) return ERRO_ARGUMENTO_INVALIDO;

	Item_lista* aRemover = lista->primeiro;
	bool_t DadoEncontrado = FALSO;

	while (aRemover != NULL){

		if (strcmp(aRemover->DadosItem->Nome, Seguidor->Nome) == 0) {

			DadoEncontrado = VERDADEIRO;
			break;
		}

		aRemover = aRemover->Proximo;
	}

	if (DadoEncontrado == VERDADEIRO) {

		if (aRemover->Anterior != NULL) aRemover->Anterior->Proximo = aRemover->Proximo;
		if (aRemover->Proximo != NULL) aRemover->Proximo->Anterior = aRemover->Anterior;
		if (aRemover == lista->primeiro) lista->primeiro = aRemover->Proximo;

		lista->Seguidores--;

		free(aRemover);
	}

	else return ERRO_DADO_NAO_ENCONTRADO;

	return SUCESSO;
}

/**
* Fun��o para testar se a lista est� vazia
* @param Lista_Aresta apontador para a lista que ser� testada
* @return VERDADEIRO caso esteja vazia e FALSO caso n�o esteja
*/
bool_t ListaArestasVazia(Lista_Aresta * lista) {

	return (lista->primeiro == NULL) ? VERDADEIRO : FALSO;
}

/**
* Fun��o que libera a memoria alocada da lista de adjacencia/amigos
* @param Lista_Aresta apontador para a lista que ser� liberada
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t LiberaListaAdjacencia(Lista_Aresta * lista) {

	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	if (lista->Seguidores == 0) return ERRO_LISTA_VAZIA;

	Item_lista* proximo = lista->primeiro;
	Item_lista* atual;

	while (proximo != NULL){

		atual = proximo;
		proximo = atual->Proximo;

		free(atual);
	}

	lista->primeiro = NULL;
	lista->Seguidores = 0;

	return SUCESSO;
}

// Manipula��o de lista Aresta - FIM

////////////////////////////////////////////////////////////////

// Manipula��o de lista Postagens - Inicio

/**
* Fun��o que cria e inicia uma lista de postagem
* @param Lista_Post_t apontador para a lista que ser� inicializada
* @return Endere�o da Lista inicializada caso de certo, caso contr�rio retornar� NULL
*/
Lista_Post_t * IniciaInicializaListaPost(Lista_Post_t * lista){
	
	lista = (Lista_Post_t*)malloc(sizeof(Lista_Post_t));

	if (lista == NULL) return NULL;

	lista->nItens = 0;
	lista->Primeira = NULL;

	return lista;
}

/**
* Fun��o que insere uma nova postagem na lista de postagens
* @param Lista_Post_t apontador para a lista que ser� alterada
* @param Post_t apontador para a postagem que ser� adicionada
* @return SUCESSO caso de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t InsereNovaPostagem(Lista_Post_t* lista, Post_t* NovaPostagem) {

	if (lista == NULL || NovaPostagem == NULL) return ERRO_ARGUMENTO_INVALIDO;

	Item_Post_t* NovoItem = (Item_Post_t*)malloc(sizeof(Item_Post_t));

	if (NovoItem == NULL) return ERRO_ALOCACAO_MEMORIA;

	NovoItem->proximo = NULL;
	NovoItem->anterior = NULL;
	NovoItem->DadosItem = NovaPostagem;

	if (lista->Primeira == NULL) {

		NovoItem->proximo = lista->Primeira;
		lista->Primeira = NovoItem;
	}

	else {

		NovoItem->proximo = lista->Primeira;
		lista->Primeira->anterior = NovoItem;
		lista->Primeira = NovoItem;
	}

	lista->nItens++;
	return SUCESSO;
}

/**
* Fun��o que remove uma postagem da lista
* @param Lista_Post_t apontador que aponta a lista que ser� alterada
* @param Unsigned int que armazena o ID da postagem que ser� removida
* @return SUCESSO caso de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t RemoverPostagem(Lista_Post_t* lista, unsigned int IDdaPostagem) {

	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	Item_Post_t* aRemover = lista->Primeira;
	bool_t DadoEncontrado = FALSO;

	while (aRemover != NULL){

		if (aRemover->DadosItem->ID == IDdaPostagem) {

			DadoEncontrado = VERDADEIRO;
			break;
		}

		aRemover = aRemover->proximo;
	}

	if (DadoEncontrado == VERDADEIRO) {
		
		if (aRemover->anterior != NULL) aRemover->anterior->proximo = aRemover->proximo;
		if (aRemover->proximo != NULL) aRemover->proximo->anterior = aRemover->anterior;
		if (aRemover == lista->Primeira) lista->Primeira = aRemover->proximo;

		if (aRemover->DadosItem->nCurtidas != 0) {

			LiberaTabela(aRemover->DadosItem->curtidas);
		}
		lista->nItens--;
		free(aRemover);
	}

	else return ERRO_DADO_NAO_ENCONTRADO;

	return SUCESSO;
}

/**
* Fun��o que imprime todas as postagens do perfil
* @param TipoDado apontador para o perfil que ter� as postagens imprimidas
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t ImprimePostagens(TipoDado * PerfilAtivo){
	
	if (PerfilAtivo == NULL) return ERRO_ARGUMENTO_INVALIDO;

	if (PerfilAtivo->postagens->nItens == 0) return LISTA_POSTAGENS_VAZIA;

	if (PerfilAtivo->postagens != NULL) {

		Item_Post_t* Imprime = PerfilAtivo->postagens->Primeira;

		printf("\n\n\tImprimindo todas as postagens de %s\n\n", PerfilAtivo->Nome);
		while (Imprime != NULL) {

			printf("\nID da postagem....: %d", Imprime->DadosItem->ID);
			printf("\n%.50s", Imprime->DadosItem->postagem);
			printf("\nNumero de curtidas: %d", Imprime->DadosItem->nCurtidas);

			Imprime = Imprime->proximo;
		}
	}

	else return LISTA_POSTAGENS_VAZIA;

	return SUCESSO;
}

/**
* Fun��o que libera a memoria alocada da lista de postagens
* @param Lista_Post_t apontador para a lista que ser� liberada
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t LiberaListaPostagens(Lista_Post_t * lista){
	
	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	if (lista->nItens == 0) return ERRO_LISTA_VAZIA;

	Item_Post_t* proximo = lista->Primeira;
	Item_Post_t* atual;

	while (proximo != NULL){
		
		atual = proximo;
		proximo = atual->proximo;

		free(atual);
	}

	lista->nItens = 0;
	lista->Primeira = NULL;

	return SUCESSO;
}

// Manipula��o de lista Postagens - FIM