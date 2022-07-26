/**
* @file		Usu�rio.h
* @brief	Arquivo com as defini��es fun��es destinadas a intera��o com o usu�rio.
* @author	Pedro Henrique Assun��o
* @date		2020-11-05
*/

#pragma once
#ifndef __usu�rio_h__
#define __usu�rio_h__

/* Inclus�es */

#include "Hash.h"

/* Constantes */

/* Tipos */

/* Fun��es Exportadas */

DataType* NovosDados(void);
char* NomeEscolhido(void);
int EscolheColuna(HashTable* table);

#endif // __Usu�rio_h__

