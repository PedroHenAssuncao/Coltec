/**
* @file		Lista.c
* @brief	Arquivo com as implementações de lista.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/

/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "Erros.h"
#include "Tipos.h"

// Manipulação de Lista - INICIO

Lista* CriaLista(void){
	
	Lista* novaLista = (Lista*)malloc(sizeof(Lista));

	if (novaLista == NULL) return NULL;

	novaLista->nItens = 0;
	novaLista->Primeiro = NULL;
	novaLista->Ultimo = NULL;

	return novaLista;
}

Erros_t InsereInicio(Lista * lista, DataType * DadosItem){
	Item_lista* novoItem = (Item_lista*)malloc(sizeof(Item_lista));

	if (novoItem == NULL) return ERRO_ALOCACAO_MEMORIA;

	novoItem->Anterior = NULL;

	if (lista->Primeiro == NULL) {

		novoItem->Proximo = lista->Primeiro;
		lista->Primeiro = lista->Ultimo = novoItem;
	}
	else
	{
		novoItem->Proximo = lista->Primeiro;
		lista->Primeiro->Anterior = novoItem;
		lista->Primeiro = novoItem;
	}

	novoItem->DadosItem = DadosItem;
	lista->nItens++;

	return SUCESSO;
}

Erros_t RemoveLista(Lista *lista, DataType * DadosItem) {

	int i;
	bool_t dadoEncontrado = FALSO;
	Item_lista* aRemover = lista->Primeiro;

	while (aRemover != NULL){

		if (aRemover->DadosItem->Telefone == DadosItem->Telefone) {
			if(strcmp(aRemover->DadosItem->Nome, DadosItem->Nome) == 0){
			
				dadoEncontrado = VERDADEIRO;
				break;
			}
		}

		aRemover = aRemover->Proximo;

	}

	if (dadoEncontrado == VERDADEIRO) {

		if (aRemover->Anterior != NULL) aRemover->Anterior->Proximo = aRemover->Proximo;
		if (aRemover->Proximo != NULL) aRemover->Proximo->Anterior = aRemover->Anterior;
		if (aRemover == lista->Primeiro) lista->Primeiro = aRemover->Proximo;
		if (aRemover == lista->Ultimo) lista->Ultimo = aRemover->Anterior;

		lista->nItens--;
		free(aRemover);
	}

	else return ERRO_DADO_NAO_ENCONTRADO;

	// Se chegou até é porque correu tudo bem
	return SUCESSO;
}

DataType * PegaItem(Lista *lista, unsigned int posicao){

	int i;
	bool_t DadoEncontrado = FALSO;
	Item_lista* DadosItem = lista->Primeiro;

	for (i = 0;i < lista->nItens ;i++) {
		
		if (posicao == i) {
			
			DadoEncontrado = VERDADEIRO;
			break;
		}

		DadosItem = DadosItem->Proximo;
	}

	return (DadoEncontrado == VERDADEIRO) ? DadosItem->DadosItem : NULL;
}

bool_t ListaVazia(Lista *lista){
	return (lista->Primeiro == NULL) ? VERDADEIRO : FALSO;
}

Erros_t DestroiLista(Lista * lista) {

	if (ListaVazia(lista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

	Item_lista* proximo = lista->Primeiro, * atual;

	while (proximo != NULL){

		atual = proximo;
		proximo = atual->Proximo;

		free(atual->DadosItem);
		free(atual);
	}

	lista->Primeiro = lista->Ultimo = NULL;
	lista->nItens = 0;

	return SUCESSO;
}
// Fim das manipulações de lista