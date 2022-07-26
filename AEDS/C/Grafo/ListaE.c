/**
* @file		ListaE.c
* @brief	Arquivo com as implementações de lista para manipular o grafo.
* @author	Pedro Henrique Assunção
* @date		2020-11-12
*/


/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Erros.h"
#include "Tipos.h"
#include "Grafo.h"
#include "ListaE.h"

// Manipulação de Lista de Vertices - INICIO

Erros_t InicializaListaVertices(Grafo * grafo) {

	if (grafo == NULL) return ERRO_ARGUMENTO_INVALIDO;

	grafo->nVertices = 0;
	grafo->PrimeiroVertice = grafo->UltimoVertice =  NULL;

	return SUCESSO;
}

Erros_t InsereInicioVertice(Grafo * grafo, TipoDado * Dados){
	
	if ((grafo == NULL) || Dados == NULL) return ERRO_ARGUMENTO_INVALIDO;

	Vertice* novoVertice = (Vertice*)malloc(sizeof(Vertice));

	if (novoVertice == NULL) return ERRO_ALOCACAO_MEMORIA;

	novoVertice->anterior = NULL;
	novoVertice->proximo = NULL;
	novoVertice->adjacentes = NULL;

	if (grafo->nVertices == 0) {

		novoVertice->proximo = grafo->PrimeiroVertice;
		grafo->PrimeiroVertice = grafo->UltimoVertice =  novoVertice;
	}

	else{

		novoVertice->proximo = grafo->PrimeiroVertice;
		grafo->PrimeiroVertice->anterior = novoVertice;
		grafo->PrimeiroVertice = novoVertice;
	}

	novoVertice->Dado = Dados;
	grafo->nVertices++;

	return SUCESSO;
}

Erros_t RemoveVertice(Grafo* grafo, TipoDado * Dado) {

	bool_t dadoEncontrado = FALSO;
	Vertice* aRemover = grafo->PrimeiroVertice;
	Erros_t erro;

	while (aRemover != NULL){

		if (aRemover->Dado->ID == Dado->ID) {
			if (strcmp(aRemover->Dado->Nome, Dado->Nome) == 0) {

				dadoEncontrado = VERDADEIRO;
				break;
			}
		}

		aRemover = aRemover->proximo;
	}

	if (dadoEncontrado == VERDADEIRO) {

		if (aRemover->anterior != NULL) aRemover->anterior->proximo = aRemover->proximo;
		if (aRemover->proximo != NULL)	aRemover->proximo->anterior = aRemover->anterior;
		if (aRemover == grafo->PrimeiroVertice) grafo->PrimeiroVertice = aRemover->proximo;
		if (aRemover == grafo->UltimoVertice) grafo->UltimoVertice = aRemover->anterior;

		erro = LiberaListaAdjacencia(aRemover->adjacentes);
		grafo->nVertices--;
		free(aRemover->Dado);
		free(aRemover);
	}

	else return ERRO_DADO_NAO_ENCONTRADO;

	return SUCESSO;
}

bool_t ListaVerticeVazia(Grafo* grafo) {
	return (grafo->PrimeiroVertice == NULL) ? VERDADEIRO : FALSO;
}

Erros_t DestroiListaVertice(Grafo* grafo) {

	if (ListaVerticeVazia(grafo) == VERDADEIRO) return ERRO_ARGUMENTO_INVALIDO;

	Vertice* proximo = grafo->PrimeiroVertice, * atual;

	while (proximo != NULL){
		
		atual = proximo;
		proximo = atual->proximo;

		LiberaListaAdjacencia(atual->adjacentes);
		free(atual->Dado);
		free(atual);
	}

	grafo->nVertices = 0;
	grafo->PrimeiroVertice = grafo->UltimoVertice = NULL;

	return SUCESSO;
}

// FIM das manipulações de Lista de vertice

// Manipulações de lista de Arestas - INICIO

Lista_Aresta* InicializaListaArestas(Lista_Aresta * lista){
	
	lista = (Lista_Aresta*)malloc(sizeof(Lista_Aresta));

	if (lista == NULL) return NULL;

	lista->nArestas = 0;
	lista->ultimaAresta = lista->primeiraAresta = NULL;

	return lista;
}

Erros_t InsereInicioListaArestas(Lista_Aresta * lista, Vertice * Origem, Vertice * Destino, TipoGrafo_t tipoDoGrafo){
	
	if ((lista == NULL) || (Origem == NULL) || (Destino == NULL)) return ERRO_ARGUMENTO_INVALIDO;
	
	Aresta* novaAresta = (Aresta*)malloc(sizeof(Aresta));

	if (novaAresta == NULL) return ERRO_ALOCACAO_MEMORIA;

	novaAresta->anterior = NULL;
	novaAresta->proximo = NULL;

	if (lista->primeiraAresta == NULL) {

		novaAresta->proximo = lista->primeiraAresta;
		lista->ultimaAresta = lista->primeiraAresta = novaAresta;
	}

	else {

		novaAresta->proximo = lista->primeiraAresta;
		lista->primeiraAresta->anterior = novaAresta;
		lista->primeiraAresta = novaAresta;
	}

	lista->nArestas++;
	novaAresta->Origem = Origem;
	novaAresta->Destino = Destino;

	if (tipoDoGrafo == eNaoEhDigrafo) {

		InsereInicioListaArestas(Destino->adjacentes, Destino, Origem, eEhDigrafo);
	}

	else return SUCESSO;

	return SUCESSO;
}

Erros_t RemoveListaAresta(Lista_Aresta * lista, Vertice * Origem, Vertice * Destino, TipoGrafo_t tipoDoGrafo){
	
	if ((lista == NULL) || (Origem == NULL) || (Destino == NULL)) return ERRO_ARGUMENTO_INVALIDO;

	Aresta* aRemover = lista->primeiraAresta;
	bool_t DadoEncontrado = FALSO;

	while (aRemover != NULL){

		if (aRemover->Origem == Origem && aRemover->Destino == Destino) {

			DadoEncontrado = VERDADEIRO;
			break;
		}

		aRemover = aRemover->proximo;
	}

	if (DadoEncontrado == VERDADEIRO) {

		if (tipoDoGrafo == eNaoEhDigrafo) {

			RemoveListaAresta(Destino->adjacentes, Destino, Origem, eEhDigrafo);
		}

		if (aRemover->anterior != NULL) aRemover->anterior->proximo = aRemover->proximo;
		if (aRemover->proximo != NULL) aRemover->proximo->anterior = aRemover->anterior;
		if (aRemover == lista->primeiraAresta) lista->primeiraAresta = aRemover->proximo;
		if (aRemover == lista->ultimaAresta) lista->ultimaAresta = aRemover->anterior;

		lista->nArestas--;
		free(aRemover);
	}

	else return ERRO_DADO_NAO_ENCONTRADO;

	return SUCESSO;
}

bool_t ListaArestasVazia(Lista_Aresta * lista) {

	return (lista->primeiraAresta == NULL) ? VERDADEIRO : FALSO;
}

Erros_t LiberaListaAdjacencia(Lista_Aresta * lista) {

	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	Aresta* proximo = lista->primeiraAresta, * atual;

	while (proximo != NULL){

		atual = proximo;
		proximo = atual->proximo;

		free(atual);
	}

	lista->ultimaAresta = lista->ultimaAresta = NULL;
	lista->nArestas = 0;

	return SUCESSO;
}