/**
* @file		Perfil.h
* @brief	Arquivo com as Fun��es exportadas destinadas a manipula��o de perfil.
* @author	Pedro Henrique Assun��o
* @date		2020-11-12
*/

#pragma once
#ifndef __perfil_h__
#define __perfil_h__

/* Inclus�es */

#include "Structs.h"
#include "Erros.h"

/* Constantes */



/* Tipos */



/* Fun��es Exportadas */

unsigned int ObtemID(void);
Erros_t NovoPerfil(TipoDado* novoDado, HashTable* table);
Erros_t RemoverPerfil(char* QuemRemover, HashTable* table);
TipoDado* AtivarPerfil(HashTable* table, char* QuemAtivar);
Erros_t AdicionarAmigo(TipoDado* PerfilAtivo, HashTable* table, char* NovoAmigo);
Erros_t RemoverAmigo(TipoDado* PerfilAtivo, HashTable* table, char* AmigoRemover);
Erros_t ImprimeListaAmigos(TipoDado* PerfilAtivo);
#endif // !__perfil_h__

