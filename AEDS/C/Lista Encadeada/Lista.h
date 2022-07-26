/**
* @file		Lista.h
* @brief	Arquivo com as definições de Lista.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/

#pragma once
#ifndef __LISTA_H__
#define __LISTA_H__

/* Inclusões */

/* Tipos */


typedef float TipoDado;

// Struct com informações sobre os itens da lista

typedef struct Item_Lista_s{

	TipoDado DadosItem;
	struct Item_Lista_s* proximo;

}Item_Lista;

// Struct com a Lista

typedef struct Lista_t {

	Item_Lista* primeiro;
	unsigned int Nitens;

}Lista;

/* Constantes */

/* Funções Exportadas*/

Lista* CriaLista(Lista* NovaLista);
Erros_t InsereInicio(Lista* lista, TipoDado ItemInserir);
Erros_t InsereOrdenado(Lista* lista, TipoDado ItemInserir);
Erros_t ProcuraItem(Lista* lista, TipoDado itemProcurado);
Erros_t RemoveItem(Lista* lista, TipoDado ItemRemover);
bool_t ListaVazia(Lista* lista);
Erros_t ImprimeListaE(Lista* minhaLista);
Erros_t DestroiLista(Lista* minhaLista);


#endif // __LISTA_H__

