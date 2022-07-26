/**
* @file		Grafo.h
* @brief	Arquivo com as definições de Grafo de lista de adjâscencia.
* @author	Pedro Henrique Assunção
* @date		2020-11-12
*/

#pragma once
#ifndef __grafo_h__
#define __grafo_h__

/* Inclusões */

#include "Erros.h"
/* Constantes */

#define TAMANHO_MAXIMO_STRING (30)

/* Tipos */

// Enumeração que contem as informações do tipo Grafo
typedef enum TipoGrafo_e
{
	eEhDigrafo,
	eNaoEhDigrafo
}TipoGrafo_t;

// Struct com as informaçoes do tipo que será armazenado no Grafo
typedef struct Pefil {

	unsigned int ID;
	char Nome[TAMANHO_MAXIMO_STRING];

}TipoDado;

typedef struct Aresta_s {

	struct Vertice_s* Origem;
	struct Vertice_s* Destino;
	struct Aresta_s* proximo;
	struct Aresta_s* anterior;
}Aresta;

typedef struct Lista_Aresta_s {

	unsigned int nArestas;
	struct Aresta_s* primeiraAresta;
	struct Aresta_s* ultimaAresta;
}Lista_Aresta;

typedef struct Vertice_s {

	TipoDado* Dado;
	struct Lista_Aresta_s* adjacentes;
	struct Vertice_s* proximo;
	struct Vertice_s* anterior;
}Vertice;

typedef struct Grafo_s {

	unsigned int nVertices;
	TipoGrafo_t TipoGrafo;
	struct Vertice_s* PrimeiroVertice;
	struct Vertice_s* UltimoVertice;
}Grafo;

/* Funções Exportadas*/

Grafo* CriaGrafo(TipoGrafo_t tipoGrafo);
Erros_t ImprimeGrafo(Grafo* grafo);
Erros_t DestroiGrafo(Grafo* grafo);
TipoDado* ObtemDados(void);
Erros_t InserirUmaAresta(Grafo* grafo, int ID_origem, int ID_Destino);
#endif // !__grafo_h__
