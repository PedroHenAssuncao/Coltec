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
#include "Tipos.h"
#include "Structs.h"
/* Constantes */

/* Tipos */

/* Funções Exportadas*/

// Funções para a manipulação da lista de Postagens - INICIO

Lista_Post_t* IniciaInicializaListaPost(Lista_Post_t* lista);
Erros_t InsereNovaPostagem(Lista_Post_t* lista, Post_t* NovaPostagem);
Erros_t RemoverPostagem(Lista_Post_t* lista, unsigned int IDdaPostagem);
Erros_t ImprimePostagens(TipoDado* PerfilAtivo);
Erros_t LiberaListaPostagens(Lista_Post_t* lista);


// Funções para a manipulação da lista de Postagens - FIM

////////////////////////////////////////////////////////////////

// Funções para a manipulação da lista de Arestas - INICIO

Lista_Aresta* InicializaListaArestas(Lista_Aresta* lista);
Erros_t InsereInicioListaArestas(Lista_Aresta* lista, Item_lista* QuemInserir);
Erros_t RemoveListaAresta(Lista_Aresta* lista, TipoDado* Seguidor);
bool_t ListaArestasVazia(Lista_Aresta* lista);
Erros_t LiberaListaAdjacencia(Lista_Aresta* lista);

// Funções para a manipulação da lista de Arestas FIM
#endif // __listae_h__
