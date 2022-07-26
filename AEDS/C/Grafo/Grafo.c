/**
* @file		Grafo.h
* @brief	Arquivo com as definições de Grafo de lista de adjâscencia.
* @author	Pedro Henrique Assunção
* @date		2020-11-12
*/

/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Grafo.h"
#include "Erros.h"
#include "Tipos.h"
#include "ListaE.h"

#pragma warning(disable: 4996)

TipoDado* ObtemDados(void) {

	TipoDado* novoDado = (TipoDado*)malloc(sizeof(TipoDado));

	if (novoDado == NULL) return NULL;

	setbuf(stdin, NULL);
	printf("\nDigite o Nome: ");
	fgets(novoDado->Nome, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);
	printf("\nDigite um ID: ");
	(void)scanf("%d", &novoDado->ID);

	return novoDado;

}

Grafo* CriaGrafo(TipoGrafo_t tipoGrafo) {

	Grafo* novoGrafo = (Grafo*)malloc(sizeof(Grafo));

	if (novoGrafo == NULL) return NULL;

	novoGrafo->TipoGrafo = tipoGrafo;

	InicializaListaVertices(novoGrafo);
	
	return novoGrafo;
}

Erros_t InserirUmaAresta(Grafo * grafo, int ID_origem, int ID_Destino) {

	if (grafo == NULL) return ERRO_ARGUMENTO_INVALIDO;

	Vertice* Origem = NULL;
	Vertice* Destino = NULL;
	Vertice* aux = grafo->PrimeiroVertice;

	while (aux != NULL){

		if (aux->Dado->ID == ID_origem) {

			Origem = aux;
		}

		if (aux->Dado->ID == ID_Destino) {

			Destino = aux;
		}

		aux = aux->proximo;
	}

	if (Origem == NULL || Destino == NULL) return ERRO_DADO_NAO_ENCONTRADO;

	else {

		Origem->adjacentes = InicializaListaArestas(Origem->adjacentes);
		InsereInicioListaArestas(Origem->adjacentes, Origem, Destino, grafo->TipoGrafo);
	}

	return SUCESSO;
}

Erros_t ImprimeGrafo(Grafo * grafo) {

	if (grafo == NULL) return ERRO_ARGUMENTO_INVALIDO;
	
	Vertice* aux = grafo->PrimeiroVertice;
	Aresta* aux_arestas;

	while (aux != NULL){

		printf("Nome...: %s", aux->Dado->Nome);
		printf("\nID...: %d", aux->Dado->ID);
		printf("\nAdjacentes: \n");
		
		if (aux->adjacentes != NULL) {

			aux_arestas = aux->adjacentes->primeiraAresta;
			while (aux_arestas != NULL) {

				printf("\nNome..: %s", aux_arestas->Destino->Dado->Nome);
				printf("\nID....: %d", aux_arestas->Destino->Dado->ID);

				aux_arestas = aux_arestas->proximo;
			}
		}

		printf("\n\n-----------------------------------\n\n");

		aux = aux->proximo;
	}

	return SUCESSO;
}

Erros_t DestroiGrafo(Grafo * grafo) {

	if (grafo == NULL) return ERRO_ARGUMENTO_INVALIDO;

	DestroiListaVertice(grafo);
	
	return SUCESSO;
}