/**
* @file		Lista.h
* @brief	Arquivo com as definições de lista.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/

#pragma once
#ifndef __lista_h___
#define __lista_h__

/* Inclusões */

#include "Hash.h"
#include "Erros.h"
#include "Tipos.h"

/* Constantes */

/* Tipos */

/* Funções Exportadas */

Lista* CriaLista(void);
Erros_t InsereInicio(Lista* lista, DataType* DadosItem);
Erros_t RemoveLista(Lista* lista, DataType* DadosItem);
DataType* PegaItem(Lista* lista, unsigned int posicao);
bool_t ListaVazia(Lista* lista);
Erros_t DestroiLista(Lista* lista);

#endif // __lista_h___

