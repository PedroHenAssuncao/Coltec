/**
* @file		BuscaBinária.h
* @brief	Arquivo com as definições de BuscaBinária.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/

#pragma once
#ifndef __buscabinária_h__
#define __buscabinária_h__

/* Inclusões */

#include "Hash.h"
#include "Erros.h"
#include "Tipos.h"

/* Constantes */

/* Tipos */

/* Funções Exportadas */

DataType** CriaVetorDePonteiros(Lista* lista);
Erros_t InsereOrdenado(Lista* lista, DataType* dadosItem);
Erros_t ImprimirDadosLista(Lista* lista);
Erros_t ImprimirDadosPessoa(DataType* dados);
DataType* BuscaDadoItem(Lista* lista, char procurado[TAMANHO_MAXIMO_STRING]);

#endif // __buscabinária_h__

