/**
* @file		Perfil.h
* @brief	Arquivo com as Funções exportadas destinadas a manipulação de perfil.
* @author	Pedro Henrique Assunção
* @date		2020-11-12
*/

#pragma once
#ifndef __perfil_h__
#define __perfil_h__

/* Inclusões */

#include "Structs.h"
#include "Erros.h"

/* Constantes */



/* Tipos */



/* Funções Exportadas */

unsigned int ObtemID(void);
Erros_t NovoPerfil(TipoDado* novoDado, HashTable* table);
Erros_t RemoverPerfil(char* QuemRemover, HashTable* table);
TipoDado* AtivarPerfil(HashTable* table, char* QuemAtivar);
Erros_t AdicionarAmigo(TipoDado* PerfilAtivo, HashTable* table, char* NovoAmigo);
Erros_t RemoverAmigo(TipoDado* PerfilAtivo, HashTable* table, char* AmigoRemover);
Erros_t ImprimeListaAmigos(TipoDado* PerfilAtivo);
#endif // !__perfil_h__

