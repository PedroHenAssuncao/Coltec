/**
* @file		Structs.h
* @brief	Arquivo com as defini��es dos tipos que ser�o usados.
* @author	Pedro Henrique Assun��o
* @date		2020-11-12
*/

#pragma once
#ifndef __structs_h__
#define __structs_h__

/* Inclus�es */

/* Constantes */

#define TAMANHO_MAXIMO_STRING (100)

/* Tipos */

/* Struct Destinada ao Perfil - INICIO*/

// Struct com as informa�oes do perfil do usu�rio
typedef struct Perfil_s {

	unsigned int ID;
	char Nome[TAMANHO_MAXIMO_STRING];
	char Email[TAMANHO_MAXIMO_STRING];
	struct Lista_post_s* postagens;
	struct Lista_Aresta_s* Seguindo;

}TipoDado;

/* Struct Destinada ao Perfil - FIM*/

/////////////////////////////////////////////////////////

/* Structs Destinadas a Postagens - INICIO */

typedef struct Postagens_s {

	unsigned int ID;
	char postagem[TAMANHO_MAXIMO_STRING];
	unsigned int nCurtidas;
	struct HashTable_s* curtidas;

}Post_t;

typedef struct Item_Postagem_s {

	Post_t* DadosItem;
	struct Item_Postagem_s* proximo;
	struct Item_Postagem_s* anterior;
}Item_Post_t;

typedef struct Lista_post_s {

	Item_Post_t* Primeira;
	unsigned int nItens;
}Lista_Post_t;

/* Structs Destinadas a Postagens - FIM*/

/////////////////////////////////////////////////////////

/* Structs destinadas a Grafo - INICIO */

// Struct que armazena informa��es do time lista de arestas
typedef struct Lista_Aresta_s {

	// Numero de arestas que existem na lista
	unsigned int Seguidores;
	// Endere�o da primeira aresta da lista
	struct Item_Lista_s* primeiro;
}Lista_Aresta;

/* Structs destinadas a Grafo - FIM */

/////////////////////////////////////////////////////////////

/* Structs destinadas a Hash Table - INICIO*/

// Struct contendo as informa��es a respeito do item da lista
typedef struct Item_Lista_s {
	TipoDado* DadosItem;
	struct Item_Lista_s* Anterior;
	struct Item_Lista_s* Proximo;
}Item_lista;

// Struct contendo as informa��es da tabela Hash
typedef struct HashTable_s {
	unsigned int nColunas;
	struct Item_Lista_s** DadosTabela;
}HashTable;

/* Structs destinadas a Hash Table */

/* Fun��es Exportadas */
#endif // !__structs_h__

