/**
* @file     Rela��es.h
* @brief    Arquivo com as fun��es exportadas de manipula��o de rela��es.
* @author   Pedro Henrique Assun��o
* @date     2020-11-12
*/

#pragma once
#ifndef __reala��es_h__
#define __reala��es_h__

/* Inclus�es */

#include "Erros.h"
#include "Structs.h"

/* Constantes */

/* Tipos */

/* Fun��es Exportadas*/

Erros_t AdicionarAmigo(TipoDado* PerfilAtivo, HashTable* table, char* NovoAmigo);
Erros_t RemoverAmigo(TipoDado* PerfilAtivo, HashTable* table, char* AmigoRemover);
Erros_t ImprimeListaAmigos(TipoDado* PerfilAtivo);
TipoDado* VisitarPerfil(TipoDado* PerfilAtivo, char* QuemVisitar);
Erros_t ImprimirNultimasPostagens(TipoDado* PerfilAtivo, TipoDado* PerfilVisitado, unsigned int Npostagens);

#endif // !__reala��es_h__
