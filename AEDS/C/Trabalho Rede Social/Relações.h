/**
* @file     Relações.h
* @brief    Arquivo com as funções exportadas de manipulação de relações.
* @author   Pedro Henrique Assunção
* @date     2020-11-12
*/

#pragma once
#ifndef __realações_h__
#define __realações_h__

/* Inclusões */

#include "Erros.h"
#include "Structs.h"

/* Constantes */

/* Tipos */

/* Funções Exportadas*/

Erros_t AdicionarAmigo(TipoDado* PerfilAtivo, HashTable* table, char* NovoAmigo);
Erros_t RemoverAmigo(TipoDado* PerfilAtivo, HashTable* table, char* AmigoRemover);
Erros_t ImprimeListaAmigos(TipoDado* PerfilAtivo);
TipoDado* VisitarPerfil(TipoDado* PerfilAtivo, char* QuemVisitar);
Erros_t ImprimirNultimasPostagens(TipoDado* PerfilAtivo, TipoDado* PerfilVisitado, unsigned int Npostagens);

#endif // !__realações_h__
