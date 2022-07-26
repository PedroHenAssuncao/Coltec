/**
* @file		ListaE.h
* @brief	Arquivo com as definições das funções de lista.
* @author	Pedro Henrique Assunção
* @date		2020-11-12
*/

#pragma once
#ifndef __listae_h__
#define __listae_h__

/* Inclusões */

#include "Erros.h"
#include "Grafo.h"
#include "Tipos.h"
/* Constantes */

/* Tipos */

/* Funções Exportadas*/

// Funções para a manipulação da lista de Vertices - INICIO

Erros_t InicializaListaVertices(Grafo* grafo);
Erros_t InsereInicioVertice(Grafo* grafo, TipoDado* Dados);
Erros_t RemoveVertice(Grafo* grafo, TipoDado* Dado);
bool_t ListaVerticeVazia(Grafo* grafo);
Erros_t DestroiListaVertice(Grafo* grafo);

// Funções para a manipulação da lista de Vertices - FIM

// Funções para a manipulação da lista de Arestas - INICIO

Lista_Aresta* InicializaListaArestas(Lista_Aresta* lista);
Erros_t InsereInicioListaArestas(Lista_Aresta* lista, Vertice* Origem, Vertice* Destino, TipoGrafo_t tipoDoGrafo);
Erros_t RemoveListaAresta(Lista_Aresta* lista, Vertice* Origem, Vertice* Destino, TipoGrafo_t tipoDoGrafo);
bool_t ListaArestasVazia(Lista_Aresta* lista);
Erros_t LiberaListaAdjacencia(Lista_Aresta* lista);

// Funções para a manipulação da lista de Arestas FIM
#endif // __listae_h__
