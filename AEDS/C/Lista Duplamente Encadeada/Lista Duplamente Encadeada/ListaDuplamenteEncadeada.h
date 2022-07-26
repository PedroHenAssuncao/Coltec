/**
* @file		ListaDuplamenteEncadeada.h
* @brief	Arquivo com as definições de Lista Duplamente Encadeada.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/

#pragma once
#ifndef __LISTADUPLAMENTEENCADEADA_H__
#define __LISTADUPLAMENTEENCADEADA_H__

/* Inclusões */

#include "Erros.h"
#include "Tipos.h"

/* Tipos */


typedef float TipoDado;

// Struct com informações sobre os itens da lista

typedef struct Item_Lista_s{

	TipoDado DadosItem;
	struct Item_Lista_s* proximo;
	struct Item_Lista_s* anterior;

}Item_Lista;

// Struct com a Lista

typedef struct Lista_t {

	Item_Lista* primeiro;
	Item_Lista* ultimo;
	unsigned int Nitens;

}Lista;

/* Constantes */

/* Funções Exportadas */

Lista* CriaLista(Lista* NovaLista);
bool_t ListaVazia(Lista* lista);
Erros_t InsereInicio(Lista* lista, TipoDado ItemInserir);
Erros_t InsereNoFim(Lista* lista, TipoDado ItemInserir);
Erros_t InsereOrdenado(Lista* lista, TipoDado ItemInserir);
Erros_t ProcuraItem(Lista* lista, TipoDado itemProcurado);
Erros_t RemoveItem(Lista* lista, TipoDado ItemRemover);
Erros_t ImprimeLista(Lista* minhaLista);
Erros_t DestroiLista(Lista* minhaLista);

#endif // __LISTADUPLAMENTEENCADEADA_H__

