/**
* @file		Hash.h
* @brief	Arquivo com as definições de hash
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/
#pragma once
#ifndef __HASH_h__
#define __HASH_h__

/* Inclusões */

#include "Erros.h"
#include "Structs.h"

/* Constantes */

/*  Tipos */


/* Funções Exportadas */

HashTable* CriaTabela(void);
unsigned int IdentificaColuna(char* string);
Erros_t InsereTabela(HashTable* table, TipoDado* DadosItem);
Erros_t RemoveTabela(HashTable* table, char nome[TAMANHO_MAXIMO_STRING]);
Erros_t ImprimeColuna(HashTable* table, unsigned int Coluna);
Erros_t ImprimeTable(HashTable* table);
Erros_t LiberaTabela(HashTable* table);
Erros_t RemoveTabelaCurtidas(HashTable* table, char nome[TAMANHO_MAXIMO_STRING]);

#endif // !__HASH_h__

