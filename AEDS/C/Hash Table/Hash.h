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

/* Constantes */

#define TAMANHO_MAXIMO_STRING  (30)

/*  Tipos */

// Struct que contem informações do enderço da pessoa
typedef struct DadosEndereco_s
{
	char Rua[TAMANHO_MAXIMO_STRING];
	char Bairro[TAMANHO_MAXIMO_STRING];
	char Cidade[TAMANHO_MAXIMO_STRING];
	unsigned int numero;
}DadosEndereco;

// Struct que contém informações sobre a pessoa
typedef struct DadosPessoa {
	char Nome[TAMANHO_MAXIMO_STRING];
	unsigned int Telefone;
	DadosEndereco* Endereco;
}DataType;

// Struct contendo as informações a respeito do item da lista
typedef struct Item_Lista_s {
	DataType* DadosItem;
	struct Item_Lista_s* Anterior;
	struct Item_Lista_s* Proximo;
}Item_lista;

// Struct contendo as informações da Lista
typedef struct Lista_s {
	unsigned int nItens;
	Item_lista* Primeiro;
	Item_lista* Ultimo;
}Lista;

// Struct contendo as informações da tabela Hash
typedef struct HashTable_s {
	unsigned int nColunas;
	Item_lista** DadosTabela;
}HashTable;


/* Funções Exportadas */

HashTable* CriaTabela(void);
int IdentificaColuna(char* string);
Erros_t InsereTabela(HashTable* table, DataType* DadosItem);
Erros_t RemoveTabela(HashTable* table, char nome[TAMANHO_MAXIMO_STRING]);
Erros_t ImprimeColuna(HashTable* table, unsigned int Coluna);
Erros_t LiberaTabela(HashTable* table);

#endif // !__HASH_h__

