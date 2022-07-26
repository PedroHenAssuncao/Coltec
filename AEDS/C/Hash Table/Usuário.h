/**
* @file		Usuário.h
* @brief	Arquivo com as definições funções destinadas a interação com o usuário.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/

#pragma once
#ifndef __usuário_h__
#define __usuário_h__

/* Inclusões */

#include "Hash.h"

/* Constantes */

/* Tipos */

/* Funções Exportadas */

DataType* NovosDados(void);
char* NomeEscolhido(void);
int EscolheColuna(HashTable* table);

#endif // __Usuário_h__

