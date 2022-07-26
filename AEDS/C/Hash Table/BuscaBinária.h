/**
* @file		BuscaBin�ria.h
* @brief	Arquivo com as defini��es de BuscaBin�ria.
* @author	Pedro Henrique Assun��o
* @date		2020-11-05
*/

#pragma once
#ifndef __buscabin�ria_h__
#define __buscabin�ria_h__

/* Inclus�es */

#include "Hash.h"
#include "Erros.h"
#include "Tipos.h"

/* Constantes */

/* Tipos */

/* Fun��es Exportadas */

DataType** CriaVetorDePonteiros(Lista* lista);
Erros_t InsereOrdenado(Lista* lista, DataType* dadosItem);
Erros_t ImprimirDadosLista(Lista* lista);
Erros_t ImprimirDadosPessoa(DataType* dados);
DataType* BuscaDadoItem(Lista* lista, char procurado[TAMANHO_MAXIMO_STRING]);

#endif // __buscabin�ria_h__

