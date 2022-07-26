/**
* @file		Hash.h
* @brief	Arquivo com as defini��es de hash
* @author	Pedro Henrique Assun��o
* @date		2020-11-05
*/
#pragma once
#ifndef __HASH_h__
#define __HASH_h__

/* Inclus�es */

#include "Erros.h"

/* Constantes */

#define TAMANHO_MAXIMO_STRING  (30)

/*  Tipos */

// Struct que contem informa��es do ender�o da pessoa
typedef struct DadosEndereco_s
{
	char Rua[TAMANHO_MAXIMO_STRING];
	char Bairro[TAMANHO_MAXIMO_STRING];
	char Cidade[TAMANHO_MAXIMO_STRING];
	unsigned int numero;
}DadosEndereco;

// Struct que cont�m informa��es sobre a pessoa
typedef struct DadosPessoa {
	char Nome[TAMANHO_MAXIMO_STRING];
	unsigned int Telefone;
	DadosEndereco* Endereco;
}DataType;

// Struct contendo as informa��es a respeito do item da lista
typedef struct Item_Lista_s {
	DataType* DadosItem;
	struct Item_Lista_s* Anterior;
	struct Item_Lista_s* Proximo;
}Item_lista;

// Struct contendo as informa��es da Lista
typedef struct Lista_s {
	unsigned int nItens;
	Item_lista* Primeiro;
	Item_lista* Ultimo;
}Lista;

// Struct contendo as informa��es da tabela Hash
typedef struct HashTable_s {
	unsigned int nColunas;
	Item_lista** DadosTabela;
}HashTable;


/* Fun��es Exportadas */

HashTable* CriaTabela(void);
int IdentificaColuna(char* string);
Erros_t InsereTabela(HashTable* table, DataType* DadosItem);
Erros_t RemoveTabela(HashTable* table, char nome[TAMANHO_MAXIMO_STRING]);
Erros_t ImprimeColuna(HashTable* table, unsigned int Coluna);
Erros_t LiberaTabela(HashTable* table);

#endif // !__HASH_h__

